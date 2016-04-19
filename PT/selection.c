#include "functii.h"

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
