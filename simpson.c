#include<stdio.h>
#include<math.h>
double func(double x){
    return log(x);
}
double simpson(double ll,double ul, double n){
    double h = (ul-ll)/n;
    double x[10],fx[10];
    for(int i=0;i<=n;i++){
        x[i] = ll + i * h;
        fx[i] = func(x[i]);
    }

    double result = 0 ;
    for(int i =0 ;i<=n ;i++){
        if(i==0 || i == n) result += fx[i];
        else if(i%2 != 0 ) result += 4*fx[i];
        else result += 2*fx[i];
    }
    result = result* (h/3);
    return result;
}
int main(){
    // int n ;
    double uv,lv,n;
    printf("Enter the number of intervals : ");
    scanf("%lf",&n);
    printf("Enter the value of upper value and lower value : ");
    scanf("%lf %lf",&uv,&lv);
    printf("resultult is : %f\n",simpson(lv,uv,n));
    return 0;
}