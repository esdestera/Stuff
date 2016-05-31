#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include "functions.c"


void cit_vector(int n, int *a);
void afisare_vector(int *a, int n);

//liste simplu inlantuite
void dispay_list(struct node *head);
void push_first(struct node *head, int val);
void push_last(struct node *head, int val);
int pop_last(struct node *head);
int pop_first(struct node *head);

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
void HeapSort(struct nod *root);
void insert(struct nod *root, int value);

//dfs
void citire_cu_muchii( FILE *test);
void citire(FILE *test);
void bfs(struct node *head, int nodStart);
void dfs_stack (struct node *head, int nodStart);
void dfs_arr(int nodStart);

//rucsac

void greedy(float greutate, int n, struct obiect a[]);
void afisare(int n, struct obiect a[]);
void citire_rucsac(float greutate, int n, struct obiect a[], FILE *f);
void ordonare(int n, struct obiect a[]);
#endif // FUNCTII_H_INCLUDED
