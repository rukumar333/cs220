#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int pid=0, targ, status;
    char childNum = 0;
    for (targ=0; targ<argc; targ++) {
	printf("Processing argument: %s\n",argv[targ]);
	if (pid==0){
	    /* childNum ++; */
	    pid=fork();
	}
    }

    while(-1!=wait(&status)){
	childNum ++;
	printf("Wait called\n");
    };
    /* printf("Wait called: %d\n", childNum); */
    return 0;
}
