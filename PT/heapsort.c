#include "functii.h"

int main(){
    int x[ ] ={6,1,8,3,10,26,21,45,2,5};
    int n=sizeof(x)/sizeof(x[0]);
    int i;
    struct nod *root = (struct nod*) malloc (sizeof(struct nod));
    root->left = NULL;
    root->right = NULL;
    root->data = max(x, n);
    for(i=0;i<n;i++){
        insert(root, x[i]);
    }
    HeapSort(root);
    return 0;
}
