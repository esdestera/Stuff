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


struct bstNode *deleteNode(struct bstNode *root,int key) {
    struct bstNode * tmp;
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
                tmp = root;
                root = root->right;
                free(tmp);
        }
        else if (root->right == NULL) {
                    tmp = root;
                    root = root->left;
                    free(tmp);
            }
        else if (root->left != NULL  && root->right != NULL) {
                tmp = findMin(root->right);
                root->data = tmp->data;
                root->right = deleteNode(root->right, root->data);
            }
        }

    return root;
}
