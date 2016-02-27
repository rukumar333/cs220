#include <stdio.h>

int main(int argc, char ** argv){
    int x; int y; int s_sum;
    unsigned int v; unsigned int w; unsigned int u_sum;
  	
    x=atoi(argv[1]);
    y=atoi(argv[2]);
    printf("%d", x);
    printf("%d", y);
    v=x;
    w=y;
    s_sum=x+y;
    u_sum=v+w;
    if (s_sum==u_sum) printf("Unsigned and signed are the same\n");
    else printf("Unsigned and signed are different\n");    
    return 1;
}
