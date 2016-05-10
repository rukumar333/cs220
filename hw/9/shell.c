#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

void parseCmd(char *buf,char **cmd, char **args, char **infile,char **outfile,int *bg);

int main() {
	char cbuf[256];
	char *cmd;
	char *argArray[10];
	char *infile;
	char *outfile;
	int bg=0;
	pid_t cpid; int cstat; pid_t pid;
	printf(":> ");
	while(fgets(cbuf,sizeof(cbuf),stdin)) {
		parseCmd(cbuf,&cmd,argArray,&infile,&outfile,&bg);
		printf("%s, %s, %s\n", infile, outfile, cmd);
		cpid=fork();
		if (cpid==0) {
			if (strlen(infile)>0) stdin=fopen(infile,"r");
			if (strlen(outfile)>0) stdout=fopen(outfile,"w");
			execve(cmd,argArray,NULL);
		}
		if (bg==0) {
			waitpid(cpid,&cstat,0);
			if (cstat!=0) printf("Command %s failed\n",cmd);
		}
		pid=waitpid(-1,&cstat,WNOHANG); // See if any background processes finished
		if (pid != -1) {
			printf("Background process %d terminated with rc=%d\n",pid,cstat);
		}
		printf(":> ");
	}
	while(-1!=(pid=wait(&cstat))) { // Wait for all the background processes to finish
		printf("Background process %d terminated with rc=%d\n",pid,cstat);
	}
	exit(0);
}

void parseCmd(char *buf,char **cmd, char **args, char **infile,char **outfile,int *bg) {
	while('\n'==buf[strlen(buf)-1]) buf[strlen(buf)-1]='\0';
	(*cmd)=strtok(buf," ");
	(*infile)="";
	(*outfile)="";
	(*bg)=0;
	char *next;
	int nargs=0;
	while((next=strtok(NULL," "))) {
		if (next[0]=='<') break;
		if (next[0]=='>') break;
		if (0==strcmp(next,"&")) break;
		args[nargs]=next;
		nargs++;
	}
	args[nargs]=NULL;
	if (next!=NULL) {
		if (next[0]=='<') {
			next++;
			(*infile)=next;
			next=strtok(NULL," ");
		}
	}
	if (next!=NULL) {
		if (next[0]=='>') {
			next++;
			(*outfile)=next;
			next=strtok(NULL," ");
		}
	}
	if (next!=NULL) {
		if (0==strcmp(next,"&")) (*bg)=1;
	}
}
