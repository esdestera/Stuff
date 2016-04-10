#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int n, i,j,it,itmax;
    float a[20][20], x[20], t[20], eps, y,s,max;
    printf("n=");
    scanf("%d",&n);
    printf("eps=");
    scanf("%f",&eps);
    printf("itmax=");
    scanf("%d",&itmax);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
        printf("a[%d][%d]=",i,j);
        scanf("%f",&a[i][j]);
    }
    for(i=1;i<=n;i++){
        printf("t[%d]=",i);
        scanf("%f",&t[i]);
    }
     for(i=1;i<=n;i++){
        printf("x[%d]=",i);
        scanf("%f",&x[i]);
    }

    it=0;

    do{
        max=0;
        for(i=1;i<=n;i++){
            s=0;
            for(j=1;j<=n;j++)
            if(j!=i){
                s=s+a[i][j]*x[j];
            }
            y=(t[i]-s)/a[i][i];
            if(max<fabs(y-x[i]))
                max=fabs(y-x[i]);
            x[i]=y;
        }
        it++;
    }while(max>eps && it<=itmax);
    if(it>itmax){
        printf("nu se poate obtine solutia in %d iteratii cu precizia %f",it,eps);
        return 1;
    }
    for(i=1;i<=n;i++)
        printf("solutia obtinuta in %d iteratii cu precizia %f este %f\n",it,eps,x[i]);
    return 0;
}
