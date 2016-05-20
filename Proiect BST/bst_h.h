#ifndef BST_H_H_INCLUDED
#define BST_H_H_INCLUDED
#include "bst_c.c"

struct bstNode *getNode(int key);
struct bstNode *insert_bst(struct bstNode *root, int key);
struct bstNode *search_node(struct bstNode *root, int key);
struct bstNode *create_bst(struct bstNode *root, int nrNode);
struct bstNode *bstSrd(struct bstNode *root);           //in-order traversal SRD;
struct bstNode *bstRsd(struct bstNode *root);           //preorder traversal RSD
struct bstNode *bstSdr( struct bstNode *root);         //postorder traversal SDR
struct bstNode *findMin(struct bstNode *root);      // return the minimum value in the tree
struct bstNode *findMax(struct bstNode *root);       // return the highest value in the tree
struct bstNode *deleteNode(struct bstNode *root, int key);   // delete the node that has a value we want
void printGivenLevel(struct bstNode* root, int level);
int height(struct bstNode* node);
void printLevelOrder(struct bstNode* root);
void freeTree(struct bstNode *root);
#endif // BST_H_H_INCLUDED
