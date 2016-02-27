#include <stdio.h>
#include <math.h>

double factorial(double n);

int main(int argv,char **argc) {

    /* int n,fn; */
    double n,fn;

    for(fn=n=1; fn>0 && fn != INFINITY; n++) {
	fn=factorial(n);
	printf("factorial(%f)=%f\n",n,fn);
    }
    return(0);

}

double factorial(double n) {
    if(n == 1) 
	return 1;
    else
	return n * factorial(n - 1);
    
}

