#include <stdio.h>
#include <stdlib.h>
void swap (int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void selection(int *a, int n){
    int i,j,imin;
    for(j=0 ;j< n-1 ; j++){
        imin=j;
        for(i= j+1 ; i<n ; i++){
            if(a[imin] > a[i])
                imin=i;
        }
    if(imin != j)
        swap(&a[j],&a[imin]);

        }
}
void afisare_vector(int *a, int n){
    int i;
    printf("elementele sunt:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void random_arr(int *arr,int n){
    int i=0;
    while(n > 0){
        arr[i] = rand() % 1000;
        i++;
        n--;
    }
}
int main()
{
    int a[100],n;
    printf("n=");
    scanf("%d",&n);
    random_arr(a,n);
    afisare_vector(a,n);
    selection(a,n);
    afisare_vector(a,n);
    return 0;
}
