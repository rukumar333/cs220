#include <stdio.h>

int func(char a[],char b[]) {
    while((*a)) if ((*a++)!=(*b++)) return 0;
    if ((*b)) return 0;
    return 1;
}

int main(){
    /* int x = 1000000001; */
    /* float fx=x; */
    /* printf("%d", x); */
    /* printf("%.7f", fx); */
    /* if (x==fx) printf("x and fx are the same"); */
    /* else printf("x and fx are different"); */

    /* char a[] = "string"; */
    /* char b[] = "string"; */
    /* if(func(a, b)){ */
    /* 	printf("True"); */
    /* }else{ */
    /* 	printf("False");	 */
    /* } */


    /* int vec[4]={6,7,8,9}; */
    /* int * vecptr=vec; */
    /* printf("Vector is at %p\n",vecptr); */
    /* printf("vec[2] is at %p\n",vecptr+2); */
    /* printf("vec[2] is not at %p\n", (char *)vecptr+2); */

    int matrix[2][3];
    int *mptr=&matrix[0][0];
    int row; int col;
    for(row=0; row<2; row++) {
	for(col=0; col<3; col++) {
	    matrix[row][col]=(row*10) + col;
	}
    }
    printf("The fifth element of matrix is %d\n",*(mptr+5));
    return 1;
}
