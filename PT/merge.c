#include"functii.h"

int main()
{
    int arr[]={5, 2, 6,1,8,4,0},n;
    n= sizeof(arr)/sizeof(arr[0]);
    afisare_vector(arr,n);
    merge_sort(arr,0,n-1);
    afisare_vector(arr,n);
    return 0;
}
