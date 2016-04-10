#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    float a[20],b[20],c[20],t[20];
    printf("n=");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("a[%d]=",i);
        scanf("%f",&a[i]);
    }

     for(i=1;i<n;i++){
        printf("b[%d]=",i);
        scanf("%f",&b[i]);
    }

    for(i=1;i<n;i++){
        printf("c[%d]=",i);
        scanf("%f",&c[i]);
    }

    for(i=1;i<=n;i++){
        printf("t[%d]=",i);
        scanf("%f",&t[i]);
    }

    for(i=1;i<n;i++){
        if(a[i]==0){
            printf("sistemul nu are solutie unica");
            return 1;
        }
        c[i]=c[i]/a[i];
        a[i+1]=a[i+1]-b[i]*c[i];
    }

    for(i=2;i<=n;i++)
        t[i]=t[i]-c[i-1]*t[i-1];

    if(a[n]==0){
        printf("sistemul nu are solutie unica");
        return 1;
    }

    t[n]=t[n]/a[n];

    for(i=n-1;i>=1;i--){
        t[i]=(t[i]-b[i]*t[i+1])/a[i];
    }
    for(i=1;i<=n;i++)
        printf("solutia %d este %f\n", i, t[i]);

    return 0;
}
