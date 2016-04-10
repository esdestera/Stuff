#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,i,j,h,k;
   float a[20][20], piv, s, aux;
   printf("n=");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
        for(j=1;j<=n+1;j++){
            printf("a[%d][%d]=",i,j);
            scanf("%f",&a[i][j]);
   }
   if(a[1][1]==0){
    i=1;
    do{
        i=i+1;
    }while(a[i][1]==0 || i<=n);
    if(i>n){
        printf("sistemul nu are solutie unica");
        return 1;
    }
    for(j=1;j<=n+1;j++){
        aux=a[1][j];
        a[1][j]=a[i][j];
        a[i][j]=aux;
    }
   }
   for(i=2;i<=n;i++){
    a[i][1]=a[i][1]/a[1][1];
   }
   for(k=2;k<=n;k++){
    i=k;
    do{
        s=0;
        for(h=1;h<=k-1;h++){
            s=s+a[i][h]*a[h][k];
        }
        piv=a[i][k]-s;
        i=i+1;
    }while(piv==0 || i<=n);
    if(piv==0){
        printf("sistemul nu are solutie unica");
        return 0;
    }
    if(i!=k+1){
        for(j=1;j<=n+1;j++){
            aux=a[k][j];
            a[k][j]=a[i-1][j];
            a[i-1][j]=aux;
        }
    }
    for(j=k;j<=n;j++){
        s=0;
        for(h=1;h<=k-1;h++){
            s=s+a[k][h]*a[h][j];
        }
        a[k][j]=a[k][j]-s;
    }
    for(i=k+1;i<=n;i++){
        s=0;
        for(h=1;h<=k-1;h++){
            s=s+a[i][h]*a[h][k];
        }
        a[i][k]=(a[i][k]-s)/a[k][k];
    }
   }
   for(i=2;i<=n;i++){
    s=0;
    for(j=1;j<=i-1;j++){
        s=s+a[i][j]*a[j][n+1];
    }
    a[i][n+1]=a[i][n+1]-s;
   }
   a[n][n+1]=a[n][n+1]/a[n][n];
   for(i=n-1;i>=1;i--){
    s=0;
    for(j=i+1;j<=n;j++){
        s=s+a[i][j]*a[j][n+1];
        a[i][n+1]=(a[i][n+1]-s)/a[i][i];
    }
   }
   printf("solutiile sunt: \n");
   for(i=1;i<=n;i++){
    printf("%f ", a[i][n+1]);
   }
   return 0;
}
