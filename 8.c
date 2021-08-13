#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double function(double x){
    return 1/x;
}

// 3/8 simpson rule function

double trapesio(){

    printf("PRECISA IMPLEMENTAR!!!!");
    return 0;
}

double UmTercoSimpson(double (*functionAsArg)(), double a, double b,int n) {
    int oddMode = 0;

    if(n % 2 != 0) {
        oddMode = 1;
        n -= 1;
    }

    double h = (b-a)/n;

    int i = 0;

    double sumOddIndex = 0;
    double sumEvenIndex = 0;

    for(i = 1; i < n; i++) {
        double y = functionAsArg(a + i * h);
        
        if(i % 2 == 0) {
            sumEvenIndex += y;
        }
        else {
            sumOddIndex += y;
        }
    }

    double y0 = functionAsArg(a);
    double yn = functionAsArg(a + h * n);

    double sum = h/3 * (y0 + yn + 4*sumOddIndex + 2*sumEvenIndex) ;
    
    if(oddMode == 1) {
        // o trapesio tem range de h* (n-1) até h*n
        sum += trapesio();
    }

    return sum;

}

int main(void) {

    double result = UmTercoSimpson(function, 1, 4, 3);

    printf("%.4lf", result);
    
    return 0;
}

