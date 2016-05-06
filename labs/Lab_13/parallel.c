#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAXKIDS 10
int childpid[MAXKIDS];

int main(int argc,char **argv) {
  int ai = 1;
  pid_t pid = -1;
  int i = 0;
  while(i < MAXKIDS && ai < argc){    
    /* childpid[i] = fork(); */
    pid = fork();
    childpid[i] = pid;
    if(pid == 0){
      char * srch;
      char * file;
      srch=argv[ai+1];
      file=argv[ai];
      int hits = numHits(file, srch);
      printf("File %s has %d instances of %s\n",file,hits,srch);
      exit(0);
    }
    ai+=2;
    i ++;
  }
  int cstat;
  int k = 0;
  while(k < i){
    waitpid(childpid[k], &cstat, NULL);
    printf("Child status: %d\n", cstat);
    k ++;
  }
  exit(0);
  /* int ai=1; */
  /* while (ai<argc) { */
    
  /*   char * srch; */
  /*   char * file; */
  /*   srch=argv[ai+1]; */
  /*   file=argv[ai]; */
  /*   pid_t pid = fork(); */
		
  /*   int hits=numHits(file,srch); */
  /*   printf("File %s has %d instances of %s\n",file,hits,srch); */
  /*   ai+=2; */
  /* } */
  /* exit(0); */

}
