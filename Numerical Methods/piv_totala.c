#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
   int n,i,j,k,c[2][2],lin,col;
    float a[20][20],piv,aux,s,eps;
   printf("n=");
   scanf("%d",&n);
   scanf("%f", &eps);
   for(i=1;i<=n;i++)
    for(j=1;j<=n+1;j++){
       printf("a[%d][%d]=",i,j);
       scanf("%f",&a[i][j]);
    }
    int npc=0;
    for(k=1;k<=n;k++){
        piv=fabs(a[k][k]);
        lin=k;
        col=k;
        for(j=k;j<=n;j++){
                for(i=k;i<=n;i++){
                    if(piv<fabs(a[i][j])){
                            piv=fabs(a[i][j]);
                            lin=i;
                            col=j;
                    }
                }
        }
        if(piv<eps){
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
        if(col!=k){
            npc++;
            c[npc][1]=k;
            c[npc][2]=col;
            for(i=1;i<=n;i++){
                aux=a[i][k];
                a[i][k]=a[i][col];
                a[i][col]=aux;
            }
        }
            for(i=k+1;i<=n;i++){
                    a[i][k]=a[i][k]/a[k][k];
            for(j=k+1;j<=n+1;j++)
                    a[i][j]=a[i][j]-a[i][k]*a[k][j];
                }
    }
    if(fabs(a[n][n]<eps)){
        printf("sistemul nu are solutie unica");
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
    if(npc!=0){
        for(i=npc;i>=1;i--){
            aux=a[c[i][1]][n+1];
            a[c[i][1]][n+1]=a[c[i][2]][n+1];
            a[c[i][2]][n+1]=aux;
        }
    }
   for(i=1;i<=n;i++)
   {
       printf("%f",a[i][n+1]);
   }
   }
