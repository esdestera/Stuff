#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
   int n, i,j,k,lin;
   float a[20][20],piv,aux,s, c[20][30]; //c=matricea initiala
   printf("n=");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
       printf("c[%d][%d]=",i,j);
       scanf("%f",&c[i][j]);
    }
    pas2: for(i=1;i<=n;i++){
        printf("a[%d][%d]=",i,n);
        scanf("%f",&a[i][n]);
    }
    for(j=n-1;j>=1;j--){
        for(i=1;i<=n;i++){
            a[i][j]=0;
            for(k=1;k<=n;k++)
                a[i][j]=a[i][j]+c[i][k]*a[k][j+1];
        }
    }
    for(i=1;i<=n;i++){
        a[i][n+1]=0;
        for(k=1;k<=n;k++)
            a[i][n+1]=a[i][n+1]+c[i][k]*a[k][1];
        a[i][n+1]=-a[i][n+1];
    }
   for(k=1;k<n;k++){
        piv=fabs(a[k][k]);
        lin=k;
        for(i=k+1;i<=n;i++){
            if(piv<fabs(a[i][k])){
                piv=fabs(a[i][k]);
                lin=i;
            }
        }
        if(piv==0){
            printf("sistemul nu are solutie unica");
            goto pas2;
        }
        if(lin!=k){
            for(j=k;j<=n+1;j++){
                aux=a[k][j];
                a[k][j]=a[lin][j];
                a[lin][j]=aux;
            }
        }
        for(i=k+1;i<=n;i++){
            a[i][k]=a[i][k]/a[k][k];
            for(j=k+1;j<=n+1;j++)
                a[i][j]=a[i][j]-a[i][k]*a[k][j];
        }
   }
   if(a[n][n]==0){
    printf("sistemul nu are solutie unica\n");
     goto pas2;
   }
   a[n][n+1]=a[n][n+1]/a[n][n];
   for(i=n-1;i>=1;i--){
       s=0;
       for(j=i+1;j<=n;j++){
           s=s+a[i][j]*a[j][n+1];
       }
       a[i][n+1]=(a[i][n+1]-s)/a[i][i];
   }
   printf("solutia este\n");
   for(i=1;i<=n;i++)
    printf(" %f",a[i][n+1]);
}
