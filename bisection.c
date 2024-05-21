#include<stdio.h>
#define EPSILON 0.01

double f(double n){
    return ((n*n*n) -(2*n) -5);
}

void bisection(double a,double b){
    if(f(a) * f(b) >= 0) {
        printf("You have not assumed correct a and b");
        return ;
    }
    double c = a;
    while(b - a >= EPSILON){
        c = (a+b)/2;
        if(f(c) == 0.0){
            break;
        }else if(f(c) * f(a) < 0) b = c;
        else a = c;
    }
    printf("The value of the root is : %lf\n",c);
}
int main(){
    double a,b;
    printf("Enter the value of a and b : ");
    scanf("%lf %lf",&a,&b);

    bisection(a,b);
    return 0;
}