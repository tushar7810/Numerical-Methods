#include<stdio.h>
float y(float x){
    return 1/(1+ x*x);
}
float trapizoidal(float a ,float b,float n){
    float h = (b -a)/n;
    float s = y(a) + y(b);
    for(int i=1;i<n;i++){
        s += 2*y(a + i*h);
    }
    return (h/2)*s;
}
int main(){
    float ul,ll,n;
    printf("Enter the number of evalyating grid : ");
    scanf("%f", &n);
    printf("Enter the upper and lower range : ");
    scanf("%f %f", &ul,&ll);
    printf("Value of the integration is : %f",trapizoidal(ll,ul,n));
    return 0;
}