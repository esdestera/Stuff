#include "bst_h.h"
int main()
{
    srand(time(NULL));
    FILE *test;     /**\file test
                       \brief the file that contains the input data
                        *the first line contain the number of nodes that are initially in the tree
                        *the second line contain the number of tests to be made
                        *the next nrTeste lines, has each two values, one for the nodes to be inserted in the tree and one for the nodes to be deleted from the tree.
                     */
    test = fopen("test.in.txt","r");
    /**\var nrTeste
        \brief the number of tests   */
    /**\var nrNode
       \brief  the initial number of nodes in the tree */
    /**\var nrNodeAdd
       \brief the number of nodes to be added in the tree   */
    /**\var nrNodeAdd
       \brief the number of nodes to be deleted from the tree   */
    int nrTeste;
    int nrNode;
    int nrNodeAdd;
    int nrNodeDel;

    struct bstNode *root = NULL;
    root = insert_bst(root, 500);

    fscanf(test,"%d",&nrNode);
    fscanf(test,"%d",&nrTeste);
    printf("Numarul de elemente din arbore este %d\n",nrNode);
    create_bst(root, nrNode);
    printLevelOrder(root);
    printf("\n\n\n");
    while(nrTeste != 0){
        printf("\n\nTESTUL: %d\n ",nrTeste);
        fscanf(test,"%d %d",&nrNodeAdd, &nrNodeDel);
        printf("\nnrNodeAdd = %d\n", nrNodeAdd);
        create_bst(root, nrNodeAdd);
        bstSdr(root);
        printf("\n\nnrNodeDel = %d\n",nrNodeDel);
        nodeDelete(root,nrNodeDel);
        bstSrd(root);

        nrTeste--;

    }
    freeTree(root);
    fclose(test);
}
