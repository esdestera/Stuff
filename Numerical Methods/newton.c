#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<conio.h>
float f(float x){
    return (2*x-log(x)-4);
}

float fprim(float x){
    return (2-1/x);
}
float g(float x){
return (tan(x)-x);
}

float gprim(float x){
return (1/(cos(x)*cos(x))-1);
}

int main()
{
    float x0,x1,dif,eps;
    int itmax,it;
    printf("numarul maxim de iteratii este: ");
    scanf("%d",&itmax);
    printf("precizia este: ");
    scanf("%f",&eps);
    printf("valoarea initiala x0= ");
    scanf("%f",&x0);
    it=0;
    do{
        x1=x0-g(x0)/gprim(x0);
        dif=fabs(x1-x0);
        x0=x1;
        it++;
    }while(dif>=eps && it<itmax);
    if(it>itmax){
        printf("nu s-a gasit solutia in %d iteratii",itmax);
        return 1;
    }
    printf("solutia obtinuta in %d iteratii cu precizia %f este %f",it,eps,x1);
    return 0;

}
