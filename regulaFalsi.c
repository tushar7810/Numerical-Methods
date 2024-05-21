#include<stdio.h>
#include<math.h>
double f(double n){
    return ((n*n*n) -(2*n) -5);
}
void RegulaFalsi(double a,double b){
    if(f(a) * f(b) >= 0 ){
        printf("You have not assumed right a and b ");
        return;
    }
    double c = a;
    for(int i=0;i< 5 ;i++){
        c = ( (a*f(b) - b*f(a)) / (f(b) - f(a)));
        if(f(c) == 0){
            break;
        }else if( f(a) * f(b) < 0){
            b = c;
        }else a = c;
    }
    printf("The root is : %lf\n", c);
}
int main(){
    double a,b;
    printf("Enter the values of a and b : ");
    scanf("%lf %lf",&a,&b);
    RegulaFalsi(a,b);
    return 0;
}