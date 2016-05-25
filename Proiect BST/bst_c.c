/*
    Binary Search Trees
    Scurtu Estera Daniela
    Grupa 10106B
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "bst_h.h"
int randomize();
struct bstNode{

    int data;               /**<information of one node*/
    struct bstNode *left;   /**<left child of the node*/
    struct bstNode *right;  /**<right child of the node*/
};
/**\struct bstNode bst_h.h bst_c.c
   \brief This is a structure for Binary Search Trees represented by a linked list with three fields,
one for information storage, one to point to the left child and one for the right child of the tree
*/
struct bstNode *getNode(int key){
    struct bstNode *node = (struct bstNode *) malloc( sizeof ( struct bstNode));
/**the new node takes the value key*/
    node->data = key;
/**because initially the node does not have any children, we make its children to NULL*/
    node->left = node->right = NULL;
    return node;
}

struct bstNode *insert_bst(struct bstNode *root, int key){
/**if the node does not exist we create it;*/
    if(root == NULL){
        root = getNode(key);
    }
/**if the value we want to put in the tree is lesser than the root information, we will insert it in the left subtree*/
    else if( key < root->data){
        root->left = insert_bst( root->left, key);
    }
/**otherwise it will be inserted it in the right subtree */
    else{
        root->right = insert_bst( root->right, key);
    }
    return root;
}

bool search_node(struct bstNode *root, int key){
    if(root == NULL){
        return false;
    }
/**i found it - the function become true*/
    else if( root->data == key){
        return true;
    }
/**if the value we are looking for is smaller than the root information, we will look for it in the left subtree*/
    else if(key < root->data){
        return search_node(root->left, key);
    }
/**otherwise we will look for it in the right subtree */
    else{
        return search_node(root->right, key);
    }
}

struct bstNode *create_bst(struct bstNode *root, int nrNode){
    int i, data;
    for( i = 0; i < nrNode; i++){
/**we insert nodes in the tree using the generation of random numbers*/
        data = rand() % 900 + 1;
        root = insert_bst(root, data);
    }
}

int bstSrd(struct bstNode *root){

    if( root == NULL){
            return 0;
    }
/**we use recursivity to traverse the left subtree of the tree as we arrive at the most left leaf, we print it, then go to the
right side and do the same thing for the right subtree*/
    bstSrd(root->left);
    printf("%d\t", root->data);
    bstSrd(root->right);

}

int bstRsd(struct bstNode *root){
    if(root == NULL){
            return 0;
    }
/** we start by printing the root of every visited node, then visit the left subtree and so with the right subtree*/
    printf("%d\t", root->data);
    bstRsd(root->left);
    bstRsd(root->right);
}

int bstSdr( struct bstNode *root){
    if(root == NULL){
            return 0;
    }
/**we to traverse the left subtree of the tree as we arrive at the most left leaf, then go to the right side and print its value*/
        bstSdr(root->left);
        bstSdr(root->right);
        printf("%d\t",root->data);

}

int height(struct bstNode* root)
{
    if (root==NULL)
        return 0;
    else
    {
/** compute the height of each subtree */
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

/** use the larger one */
        if (leftHeight > rightHeight){
            return(leftHeight+1);
        }
        else{
                return (rightHeight+1);
        }
    }
}

int printGivenLevel(struct bstNode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d\t", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);

    }
}

void printLevelOrder(struct bstNode* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++){
        printGivenLevel(root, i);

    }
}

struct bstNode *findMin(struct bstNode *root){
/**if the tree is empty the function will return 0;*/
    if(root == NULL){
        printf("the tree is empty");
        return 0;
    }
/**else,we will move in the left subtree while there is a left child*/
    else if( root->left == NULL){                   // ,
        return root;
    }

    return findMin(root->left);
}

struct bstNode *deleteNode(struct bstNode *root,int key) {
    struct bstNode * temp;
/** if the tree is empty the function will return the root address */
    if (root == NULL) {
        return root;
    }
/**if the value is smaller than the value of the root, then the waned value will be searched in the left subtree*/
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
/**if the value is greater than the value of the root, then the waned value will be searched in the right subtree*/
    else if (key > root->data) {
            root->right = deleteNode(root->right, key);
    }
/**we found the wanted value and three cases can be distinguished
        -# Case 1 - the node doesn't have any child
        -# Case 2 - the node has only one child
        -# Case 3 - the node has both left and right children
*/
/**\brief Case 1: no children

   * we simply deallocate the node from memory using free function and make it points to NULL*/
    else {
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
/**\brief Case 2: one child

 * there can be 2 situations, the node can have either the left node or a right node, the algorithm is similar for both of them
 */
 /**
 -if the node has a right child, we will use a auxiliary variable which will take the address of the node to be deleted while the
 node become its right child, the only thing that remains to be done is to deallocate the memory stored in the temporary variable
 */
        else if (root->left == NULL) {
                temp = root;
                root = root->right;
                free(temp);
        }
 /**
 -if the node has a left child, we will use a auxiliary variable which will take the address of the node to be deleted while the
 node become its left child, the only thing that remains to be done is to deallocate the memory stored in the temporary variable
 */
        else if (root->right == NULL) {
                    temp = root;
                    root = root->left;
                    free(temp);
            }
/**\brief Case 3 - two children

*we will use the function  findMin to find the minimum value in the right subtree, its address will be stored in the variable temp
next step is to copy the value of the minimum value in the node that has the wanted value.Now we have two nodes with the same value and
we can be in any case described above so we have to recall the function  deleteNode with the parameters root->right, the right child
of the current node and root->data */
        else if (root->left != NULL  && root->right != NULL) {
                temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, root->data);
            }
        }

    return root;
}

void freeTree(struct bstNode *root) {
    if (root == NULL) {
        return;
    }
/**delete the left subtree*/
    freeTree(root->left);
/**delete the right subtree*/
    freeTree(root->right);
/**delete the root*/
    free(root);
}

