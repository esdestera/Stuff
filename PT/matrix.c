int main()
{
    int arr[] = {1, 2, 3, 4, 3, 2, 5, 7,5 };
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Minimum number of multiplications is %d ",MatrixChainOrder(arr, 1, n-1));
    return 0;
}
