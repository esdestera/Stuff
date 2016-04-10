#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functii.h"

void swap(int a, int b){
    int aux=a;
    a=b;
    b=aux;
}

void cit_elem(int n){
    printf("n=");
    scanf("%d",&n);
}

void cit_vector(int n, int *a){
    int i;
    for(i=0;i<n;i++){
        printf("a[%d]=");
        scanf("%d",&a[i]);
    }
}

void afisare_vector(int *a, int n){
    int i;
    printf("elementele vectorului sunt: \n")
    for(i=0;i<=n;i++){
            printf("a[%d]= ",i,a[i]);
    }
}

