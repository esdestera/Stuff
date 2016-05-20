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
struct bstNode{                         // a structure for binary search tree which can be seen as a double linked list

    int data;
    struct bstNode *left;
    struct bstNode *right;
};
struct bstNode *getNode(int key){       // create a node in a tree and return its adress
    struct bstNode *node = (struct bstNode *) malloc( sizeof ( struct bstNode));
    node->data = key;
    node->left = node->right = NULL;     // because initially the node does not have any children, we make its children to NULL
    return node;
}

struct bstNode *insert_bst(struct bstNode *root, int key){     // insert a new node in the tree using recursivity
    if(root == NULL){
        root = getNode(key);                                // if the node does not exist we create it;
    }
    else if( key < root->data){
        root->left = insert_bst( root->left, key);              //if the value we want to put in the tree is less
                                                            //or equal than the root information, we will insert
                                                    //it in the left side of the tree
    }
    else{
        root->right = insert_bst( root->right, key);
    }
    return root;
}

struct bstNode *search_node(struct bstNode *root, int key){             // search for a given value in the tree
    if(root == NULL){
        return false;
    }
    else if( root->data == key){
        return root;
    }
    else if(key <= root->data){
        return search_node(root->left, key);
    }
    else{
        return search_node(root->right, key);
    }
}

struct bstNode *create_bst(struct bstNode *root, int nrNode){
    int i, data;
    for( i = 0; i < nrNode; i++){
        data = rand() % 500 + 1;
        root = insert_bst(root, data);
    }
}



/* Print nodes at a given level */
void printGivenLevel(struct bstNode* root, int level)
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

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct bstNode* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        /* use the larger one */
        if (leftHeight > rightHeight){
            return(leftHeight+1);
        }
        else{
                return (rightHeight+1);
        }
    }
}
/* Print nodes at a given level */
void printLevelOrder(struct bstNode* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++){
        printGivenLevel(root, i);

    }
}

struct bstNode *bstSrd(struct bstNode *root){           //in-order traversal SRD;

    if( root == NULL){
            return 0;
    }
    bstSrd(root->left);                         //we use recursivity to traverse the left subtree of the tree
                                                // as we arrive at the most left leaf, we print it, go to the
                                                //right side and do the same thing for the right subtree
    printf("%d\t", root->data);
    bstSrd(root->right);

}

struct bstNode *bstRsd(struct bstNode *root){           //preorder traversal RSD
    if(root == NULL){
            return 0;
    }
    printf("%d\t", root->data);                 // we start by printing the root of every visited node,
                                            //then visit the left subtree and so with the right subtree
    bstRsd(root->left);
    bstRsd(root->right);
}

struct bstNode *bstSdr( struct bstNode *root){          //postorder traversal SDR
    if(root == NULL){
            return 0;
    }
        bstSdr(root->left);
        bstSdr(root->right);
        printf("%d\t",root->data);

}

struct bstNode *findMin(struct bstNode *root){      // return the minimum value in the tree
    if(root == NULL){                               // if the tree is empty the function will return 0;
        printf("the tree is empty");
        return 0;
    }
    else if( root->left == NULL){                   // else,we will move in the left subtree while there is a left child,
        return root;
    }

    return findMin(root->left);
}

struct bstNode *findMax(struct bstNode *root){         // return the highest value in the tree
    if(root == NULL){
        printf("the tree is empty");
        return 0;
    }
    else if(root->right == NULL){                       // else,we will move in the right subtree while there is a right child,
        return root;
    }

    return findMax(root->right);

}

struct bstNode *deleteNode(struct bstNode *root,int key) {
    struct bstNode * temp;
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
            root->right = deleteNode(root->right, key);
    }
    else {

        if (root->left == NULL) {
                temp = root;
                root = root->right;
                free(temp);
        }
        else if (root->right == NULL) {
                    temp = root;
                    root = root->left;
                    free(temp);
            }
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
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/*
struct bstNode *deleteNode(struct bstNode *root,int key)
{
    struct bstNode *find = search_node(root, key);
    struct bstNode *temp;
    if(root == NULL ){
        return 0;
    }
    if(find == NULL){
        return find;
    }
    else if(find->left == NULL && find->right == NULL){
        free(find);
        find == NULL;

    }
    else if(find->left != NULL && find->right == NULL){

        temp = find;
        find = find->left;
        free(temp);
    }
    else if(find->left == NULL && find->right != NULL){
        temp = find;
        find = find->right;
        free(temp);
    }
    else if(find->left != NULL && find->right != NULL){
        struct bstNode *min = findMin(find->right);
        find->data = min->data;
        find->right = deleteNode(find->right,min->data);
    }
    return find;
}
*/
/*struct bstNode *delete_node(struct bstNode *root, int key){     // delete the node that has a value we want
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
*/


