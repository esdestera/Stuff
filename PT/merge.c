#include"functii.h"

int main()
{
    int arr[200],n;
    srand(time(NULL));
    printf("n= ");
    scanf("%d", &n);
    random_arr(arr,n);
    afisare_vector(arr,n);
    merge_sort(arr,0,n-1);
    afisare_vector(arr,n);
    return 0;
}
