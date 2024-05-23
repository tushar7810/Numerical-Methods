#include<stdio.h>
int main(){
    int i,j,n;
    float a,u,h,p,q,sum,x[6],y[6][6];
    printf("Enter the value of n : ");
    scanf("%d",&n);
    printf("ENter the value of x : \n");
    for(i=0;i<n;i++){
        scanf("%f",&x[i]);
    }
    printf("Enter the values of y : \n");
    for(i=0;i<n;i++){
        scanf("%f",&y[i][0]);
    }
    for(j=1;j<n;j++){
        for(i=j;i<n;i++){
            y[i][j] = y[i][j-1] - y[i-1][j-1];
        }
    }
    printf("Backward Differnce Table \n");
    for(i = 0 ; i < n ; i++){
        printf("%f\t",x[i]);
        for(j = 0 ; j <= i ; j++){
            printf("%f\t",y[i][j]);
        }
        printf("\n");
    }
    printf("Enter the value of interpolating point : ");
    scanf("%f",&a);
    h = x[1] - x[0];
    u = (a - x[n-1]) /h;
    sum = y[n-1][0];
    p = 1,q=1;
    for(j=1;j<n;j++){
        p = p*j;
        q = q*(u +j-1);
        sum = sum + ((q*y[n-1][j])/p);
    }
    printf("The sum is : %.4f\n",sum);
    return 0;
}

/*

gcc newton_backword.c
./a.exe -> for windows
./a.out -> for Linux or Mac


Enter the value of n : 5
ENter the value of x : 
1891
1901
1911
1921
1931
Enter the values of y :
46 66 81 93 101
Backward Differnce Table
1891.000000     46.000000
1901.000000     66.000000       20.000000
1911.000000     81.000000       15.000000       -5.000000
1921.000000     93.000000       12.000000       -3.000000       2.000000
1931.000000     101.000000      8.000000        -4.000000       -1.000000       -3.000000
Enter the value of interpolating point : 1925
The sum is : 96.8368

*/