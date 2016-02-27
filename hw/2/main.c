#include <stdio.h>
#include <stdlib.h>


int main(int argc,char **argv) {
    int x;
    x=getFirst(23);
    if(x == 12) printf ("X is 12");
    else printf ("X is %d", x);
    if (x==12) return 1;

    /* printf("%d", argc); */
    /* printf("%s", argv[1]); */
    /* int x; */
    /* x=14; */
    /* x=x++; */
    /* printf("%d", x); */

    /* int x=atoi(argv[1]); */
    /* int y=(x | (-1-x)); */
    /* if (y==-1) printf("Does OR act the same as ADD?\n"); */
    /* return 0;     */
}

int getFirst(int st) {
    return (st*124639 % 332167);
}
