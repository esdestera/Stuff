#include "functii.h"
int main()
{
  int a[100],n;
    printf("n=");
    scanf("%d",&n);
    random_arr(a,n);
    afisare_vector(a,n);
    insertion(a,n);
    afisare_vector(a,n);
    return 0;
}


struct bstNode *delete_node(struct bstNode *root, int key){     // delete the node that has a value we want
    if(search_bst(root, key) == false ){
        printf("the value has not been find!");
        return 0;
    }
    if( root == NULL ){                           //if the tree is empty the function will return the root address
        return root;
    }
    else if ( key < root->data ){               //if the value is less than the value of the root,
                                                //then the waned value will be searched in the left subtree
        root->left = delete_node(root->left,key);
    }
    else if( key > root->data){                 //if the value is bigger than the value of the root,
                                                //then the waned value will be searched in the left subtree
        root->right = delete_node(root->right,key);
    }
    else{                               // the value has been find and there may be three cases

        if(root->left == NULL && root->right == NULL){  //if the node does not have any children we delete the node
            free (root);                                //logical deletion
            root = NULL;
        }
        else if(root->left == NULL ){           // if the node has only  right children, we will use an auxiliary variable
            struct bstNode *aux = root;         // it will store the address of the wanted node
            root = root->right;                 // the node that has the value we want become the right child that the node has
            free(aux);                          // the node will be deleted
        }
        else if(root->right == NULL){           // if the node does not have any right children, we will use an auxiliary variable
            struct bstNode *aux = root;         // the auxiliary variable  will store the address of the wanted node
            root = root->left;                  // the node that has the value we want become the left child that the node has
            free(aux);                           // the node will be deleted
        }
        else{
            struct bstNode *aux = findMin(root->right);         // we are looking for the minimum value in the
                                                        //right subtree, and we store it in the variable aux;
            root->data = aux->data;                         //we put the value we find in place of the value we want to delete
            root->right = delete_node(root->right,aux->data);     //we delete the node that fist had the minimum value
        }
       return root;
    }
}
