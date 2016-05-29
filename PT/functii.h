#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include "functions.c"


void cit_vector(int n, int *a);
void afisare_vector(int *a, int n);

//liste simplu inlantuite
void dispay_list(struct node *head);
void push_first(struct node *head, int val);
void push_last(struct node *head, int val);
void pop_last(struct node *head);
void pop_first(struct node *head);

//merge sort
void random_arr(int *arr,int n);
void merge(int *arr, int left, int right,int middle);
void merge_sort(int *arr, int left, int right );

//selection sort
void swap(int *a, int *b);
void selection(int *a, int n);

//insertion sort
void insertion(int *a, int n);

// shell sort
void shell(int *a, int n);

//heapsort
void createHeap(int n,struct nod *root);
int max(int x[], int n);
void HeapSort(struct nod *root);
void insert(struct nod *root, int value);

//dfs
void citire(int nrNoduri, int nrMuchii, FILE *test);
void dfs (struct node *head, int nodStart);
void dfs1 ( int nodStart);
//bsf
void dfs (struct node *head, int nodStart);


#endif // FUNCTII_H_INCLUDED
