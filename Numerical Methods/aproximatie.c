#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<conio.h>
float g(float x){
    return ( sqrt(10)/(sqrt(x+4)));
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
        x1=g(x0);
        dif=fabs(x1-x0);
        x0=x1;
        it++;
    }while(dif >= eps && it < = itmax);
    if(it > itmax){
        printf("nu s-a gasit solutia in %d iteratii", itmax);
        return 1;
    }
    printf("solutia obtinuta in %d iteratii cu precizia %f este %f",it,eps,x1);
    return 0;

}
