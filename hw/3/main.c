#include <stdio.h>
#include <math.h>
#include <float.h>

int main(){
    /* float max = 0x7f7fffff; */
    /* float m = FLT_MIN; */
    /* printf("%.10f\n", max); */
    /* printf("%.40f\n", FLT_MIN); */
    /* printf("%.10f\n", m); */
    /* printf("hex is %fx\n", m); */
    /* float onethird = 1.0/3.0; */
    /* float sum = 0.0; */
    /* int i = 0; */
    /* for(i = 0; i < 3000; i ++){ */
    /* 	sum = sum + onethird; */
    /* } */
    /* if(sum == 1000.0){ */
    /* 	printf("Just as I expected, 3000 * 1/3 is 1000\n"); */
    /* }else{ */
    /* 	printf("%.30f\n", sum); */
    /* 	printf("That did not work!\n"); */
    /* } */
    /* float x=1e8; */
    /* float pi=3.14; */
    /* float y = (x + (-x))+pi; */
    /* float z = x + ((-x) + pi); */
    /* float f = (pi + x) + (-x); */
    /* printf("%.40f\n", y); */
    /* printf("%.40f\n", z); */
    /* printf("%.40f\n", f); */
    /* if (y==z) printf("This is an example of the associative property.\n"); */
    /* else printf("This is a counter-example.. the associative property does not hold!\n"); */
    
    float exp = -128;
    float pow = powf(2.0, exp);
    printf("%.7f\n", pow);
    printf("0x%x\n", *(unsigned int *)&pow);

    /* int x = 16843009; */
    /* int y = 1222151; */
    /* printf("0x%x\n", x); */
    /* printf("0x%x\n", htonl(x)); */
    /* printf("0x%x\n", y); */
    /* printf("0x%x\n", htonl(y)); */

    return 1;
}
