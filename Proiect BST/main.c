#include "bst_h.h"
int main()
{

    int *nrTeste,nrNoduriAdaug, nrNoduriSters,rootValue, val, x[20], i;
    struct bstNode *root = NULL;
    srand(time(NULL));
    //scanf("%d",&nrTeste);
    root = insert_bst(root, 200);
    create_bst(root,20);
    printLevelOrder(root);
    printf("\n\n\n");
   // scanf("%d", &val);
    for(i=1;i<=20;i++){
        x[i]= rand()%500;
        printf(" %d ", x[i]);
    }
    printf("\n\n");
     for(i=1;i<=20;i++){
            val = x[i];
       root = insert_bst(root, val);
    }
    bstSrd(root);

    printf("\n\n");
    for(i=1;i<=20;i++){
            val = x[i];
       root = deleteNode(root, val);
    }
    printLevelOrder(root);
   /* while(nrTeste > 0){
        scanf("%d",&nrNoduriAdaug);
        create_bst(root,nrNoduriAdaug);
        printf("LEVEL ORDER TRAVERSAL: \n");
        printLevelOrder(root);
      //  printf("val= ");
       // scanf("%d",&val);
       // delete_node(root, val);
        printf("\nSRD: \n");
        bstSrd(root);
        free(root);
        nrTeste--;
    }*/

}
