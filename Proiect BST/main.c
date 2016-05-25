#include "bst_h.h"
int main()
{
    srand(time(NULL));
    FILE *test;
    test = fopen("test.in.txt","r");

    int nrTeste;
    int nrNode;
    int nrNodeAdd;
    int nrNodeDel;
    int a[60];

    struct bstNode *root = NULL;
    root = insert_bst(root, 500);

    fscanf(test,"%d",&nrNode);
    fscanf(test,"%d",&nrTeste);
    printf("Numarul de elemente din arbore este %d\n",nrNode);
    create_bst(root, nrNode);
    printLevelOrder(root);
    printf("\n\n\n");
    while(nrTeste != 0){
        printf("\n\nTESTUL: %d\n\n ",nrTeste);
        fscanf(test,"%d %d",&nrNodeAdd, &nrNodeDel);
        create_bst(root, nrNodeAdd);
        bstSdr(root);
        printf("\n\n");
        nodeDelete(root,nrNodeDel);
        bstSrd(root);

        nrTeste--;

    }
    freeTree(root);
    fclose(test);






}
