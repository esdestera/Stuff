#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

void swap(int a, int b);
void cit_vector(int n, int *a);
void cit_elem(int n);
void afisare_vector(int *a, int n)

//liste simplu inlantuite 
void dispay_list(struct node *head);
void push_first(struct node *head, int val);
void push_last(struct node *head, int val);
void rem_last(struct node *head);
int rem_first(struct node *head);

#endif // FUNCTII_H_INCLUDED
