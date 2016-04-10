#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k;
    float a[20][20], s;
    printf("n=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n+1;j++){
        printf("a[%d][%d]=",i,j);
        scanf("%f",&a[i][j]);
    }
    for(k=1;k<=n-1;k++){
        if(a[k][k]!=0){
            for(i=k+1;i<=n;i++){
                a[i][k]=a[i][k]/a[k][k];
                for(j=k+1;j<=n+1;j++)
                    a[i][j]=a[i][j]-a[i][k]*a[k][j];
            }
        }
        else
            return 1;
    }
    if(a[n][n]==0){
        printf("sistemul nu are solutie unica");
        return 1;
    }
    a[n][n+1]=a[n][n+1]/a[n][n];
    for(i=n-1;i>=1;i--){
        s=0;
        for(j=i+1;j<=n;j++)
            s=s+a[i][j]*a[j][n+1];
        a[i][n+1]=(a[i][n+1]-s)/a[i][i];
    }
    for(i=1;i<=n;i++){
        printf("x%d= %f",i, a[i][n+1]);
    }
}
