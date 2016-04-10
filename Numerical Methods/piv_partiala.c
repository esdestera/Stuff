#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
   int n, i,j,k,lin;
   float a[20][20],piv,aux,s;
   printf("n=");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
    for(j=1;j<=n+1;j++){
       printf("a[%d][%d]=",i,j);
       scanf("%f",&a[i][j]);
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
            return 0;
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
     return 0;
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
