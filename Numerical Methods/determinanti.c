#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    float det=1,a[20][20],aux;
    printf("n=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
        printf("a[%d][%d]=",i,j);
        scanf("%f",&a[i][j]);
    }
    do{
        if(a[1][1]==0){
            i=2;
            while(i<=n && a[i][1]==0)
                i++;
            if(i>n){
                printf("detA=0");
                return 1;
            }
            for(j=1;j<=n;j++){
                aux=a[1][j];
                a[1][j]=a[i][j];
                a[i][j]=aux;
            }
            det=-det;
        }
        for(i=1;i<=n-2;i++)
            det=det*a[1][1];
        for(i=2;i<=n;i++)
            for(j=2;j<=n;j++)
                a[i][j]=a[i][j]*a[1][1]-a[i][1]*a[1][j];
        n--;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=a[i+1][j+1];
    }while(n!=1);
    det=a[1][1]/det;
    printf("determinantul este %f",det);
    return 0;
}
