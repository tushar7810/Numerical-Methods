#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float u_cal(float u,int n){
    float temp = u;
    for(int i=1;i<n;i++){
        temp = temp * (u+i);
    }
    return temp;
}
int fact(int n){
    int f = 1;
    for(int i=2;i<=n;i++){
        f *= i;
    }
    return f;
}

int main(){
    int n ;
    printf("Enter the number of values : ");
    scanf("%d",&n);
    float x[n],y[n][n];

    printf("Enter the value of x : \n");
    for(int i = 0;i<n;i++){
        scanf("%f",&x[i]);
    }
    printf("Enter the values of y : \n");
    for(int i =0;i<n;i++){
        scanf("%f",&y[i][0]);
    }

    for(int i=1;i<n;i++){
        for(int j = n-1 ; j >= 1 ; j--){
            y[j][i] = y[j][i-1] - y[j-1][i-1];
        }
    }

    printf("Backword Difference Table is : ");
    for(int i = 0;i<n;i++){
        printf("%.2f\t",x[i]);
        for(int j=0;j<i;j++){
            printf("%.6f\t",y[i][j]);
        }
        printf("\n");
    }
    float value;
    printf("Enter the value : ");
    scanf("%f",value);
    float sum = y[n-1][0];
    float u = (value - x[n-1]) / (x[1] - x[0]);
    for(int i=1;i<n;i++){
        sum = sum + ((u_cal(u,i) * y[n-1][i])/ fact(i));
    }
    printf("The Backward Evaluation is : %.6f\n",sum);

}