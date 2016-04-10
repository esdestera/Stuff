#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
   int n,k,i;
   float a[20],b[20],c[20],p,q,eps, delta,r,s,x1,x2,y1,y2;
   printf("n=");
   scanf("%d",&n);
   for(i=0;i<=n;i++){
    printf("a[%d]=",i);
    scanf("%f",&a[i]);
   }
   while(n>2){
    printf("eps=");
    scanf("%f",&eps);
    printf("p=");
    scanf("%f",&p);
    printf("q=");
    scanf("%f",&q);
    do{
        b[0]=a[0];
        b[1]=a[1]- p*b[0];
        for(k=2;k<=n;k++)
            b[k]=a[k]-p*b[k-1]-q*b[k-2];
        c[0]=b[0];
        c[1]=b[1]-p*c[0];
        for(k=2;k<n;k++)
            c[k]=b[k]-p*c[k-1]-q*c[k-2];
        delta=c[n-2]*c[n-2]-c[n-1]*c[n-3]+b[n-1]*c[n-3];
        r=b[n]*c[n-3]-b[n-1]*c[n-2];
        s=b[n-1]*c[n-1]- b[n-1]*b[n-1]- b[n]*c[n-2];
        p=p-r/delta;
        q=q-s/delta;
    } while(fabs((r+s)/2)>eps);
    printf("p=%f \n q=%f ",p,q);
    if(p*p-4*q>=0){

        y1=-p;
        y2=sqrt(p*p-4*q);
        x1=(y1 - y2)/2;
        x2=(y1 +y2)/2;
        printf("x1= %f\t%f=",x1,x2);
    }
    else{
        y1=-p/2;
        y2=sqrt(p*p-4*q);
        printf("x1=(%f-i*%f)/2\t\tx2=(%f+i*%f)/2",y1,y2,y1,y2);
    }
    n=n-2;
    for(k=0;k<=n;k++)
        a[k]=b[k];
   }

   if(n==1){
    printf("se obtine un factor liniar b0*X+b1 cu solutia ");
    printf("x1=-%f/%f\n",b[1],b[0]);
   }
   else{
        printf("\nse obtine un factor patratic b0*b[0]+b1*x+b2 \n");
    if(b[1]*b[1]-4*b[0]*b[2]>=0){
        y1=sqrt(b[1]*b[1]-4*b[0]*b[2]);
        x1=(-b[1]-y1)/(2*b[0]);
        x1=(-b[1]+y1)/(2*b[0]);
        printf("x1=%f \t x2=%f",x1,x2);
    }
    else{
        y1=-b[1]/(2*b[0]);
        y2=sqrt(4*b[0]*b[2]-b[1]*b[1])/(2*b[0]);
        printf("x1=%f-i* %f\n",y1,y2);
        printf("x2=%f+i* %f",y1,y2);
    }

}}
