#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double function(double x){
    return x*x;
}

// 3/8 simpson rule function

double TresOitavosSimpson(double (*functionAsArg)(), double a, double b,double n) {
    double h = (b-a)/n;

    int i = 0;

    double sumYIsMod3 = 0;
    double sumYIsNotMod3 = 0;

    for(i = 1; i < n; i++) {
        double y = functionAsArg(a + i * h);
        
        if(i % 3 == 0) {
            sumYIsMod3 += y;
        }
        else {
            sumYIsNotMod3 += y;
        }
    }

    double y0 = functionAsArg(a);
    double yn = functionAsArg(a + h * n);

    double sum = 3 * h * (y0 + yn + 2*sumYIsMod3 + 3*sumYIsNotMod3)/ 8 ;

    return sum;

}

int main(void) {

    double result = TresOitavosSimpson(function, 0, 1, 6);

    printf("%.2lf", result);
    
    return 0;
}

