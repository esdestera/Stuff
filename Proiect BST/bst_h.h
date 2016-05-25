#ifndef BST_H_H_INCLUDED
#define BST_H_H_INCLUDED
#include "bst_c.c"
/**\fn struct bstNode *getNode(int key);
    \brief A struct bstNode procedure for creating a new node
    \param key an integer - the value of the node
    \return the address of the new node
*/
struct bstNode *getNode(int key);
/**\fn struct bstNode *insert_bst(struct bstNode *root, int key);
   \brief A struct bstNode function to insert an element
   \param root a pointer of type struct bstNode - the address of the root(first element)
   \param key an integer - the value to be inserted
   \return the address of the inserted node
*/
struct bstNode *insert_bst(struct bstNode *root, int key);
/**\fn bool search_node(struct bstNode *root, int key);
   \brief A boolean function to search for an element in the tree
   \param root a struct bstNode pointer - the address of the root
   \param key an integer - the value to be searched for
   \return true if the value exist in the tree
   \return false if the value doesn't exist
*/
bool search_node(struct bstNode *root, int key);
/**\fn struct bstNode *create_bst(struct bstNode *root, int nrNode);
   \brief function that generates a binary tree inserting random values in the nodes
   \param root of struct bstNode type - first element address
   \param nrNode an integer - the number of nodes in the tree
   \return doesn't return anything
*/
struct bstNode *create_bst(struct bstNode *root, int nrNode);
/**\fn int bstSrd(struct bstNode *root);
   \brief a function that prints the in-order traversal for a tree
   \param root a struct bstNode variable - address of the first element
   \return 0, when reach the end of the tree
*/
int bstSrd(struct bstNode *root);
/**\fn void bstRsd(struct bstNode *root);
   \brief a function that prints the pre-order traversal for a tree
   \param root a struct bstNode variable - address of the root
   \return 0, when reach the end of the tree
*/
int bstRsd(struct bstNode *root);
/**\fn void bstSdr(struct bstNode *root);
   \brief a function that prints the post-order traversal for a tree
   \param root a struct bstNode variable - address of the root
   \return 0, when reach the end of the tree
*/
int bstSdr( struct bstNode *root);
/**\fn struct bstNode *findMin(struct bstNode *root);
   \brief find the smallest value in the tree
   \param root a struct bstNode variable - address of the first element
   \return the address of the node with the smallest value
*/
struct bstNode *findMin(struct bstNode *root);
/** \fn struct bstNode *deleteNode(struct bstNode *root, int key);
    \brief function that delete a node which has a value we want to delete
    \param root a struct bstNode - address of the root
    \param key an integer - the value of the node we try to delete
    \return the address of the deleted node
*/
struct bstNode *deleteNode(struct bstNode *root, int key);
/**\fn void printGivenLevel(struct bstNode* root, int level);
   \brief a void function that print the nodes from a given level
   \param root struct bstNode - address of the root
   \param level an integer - the level whose nodes  we want to print
   \return nothing
*/
int printGivenLevel(struct bstNode* root, int level);
/**\fn  int height(struct bstNode* node);
   \brief Compute the "height" of a tree the number of nodes along the longest path from the root node down to the farthest leaf node.
   \param root struct bstNode pointer - address of the root
   \return the height of the tree
*/
int height(struct bstNode* root);
/**\fn void printLevelOrder(struct bstNode* root);
   \brief prints the nodes of the tree in level order
   \param root struct bstNode pointer - the address of the first element
   \return nothing
*/
void printLevelOrder(struct bstNode* root);
/**\fn void freeTree(struct bstNode *root);
   \brief delete a BST
   \param root struct bstNode - address of the root
   \return nothing
*/
void freeTree(struct bstNode *root);
#endif // BST_H_H_INCLUDED
