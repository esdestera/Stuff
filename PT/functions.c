#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functii.h"

void swap(int a, int b){
    int aux=a;
    a=b;
    b=aux;
}

void cit_elem(int n){
    printf("n=");
    scanf("%d",&n);
}

void cit_vector(int n, int *a){
    int i;
    for(i=0;i<n;i++){
        printf("a[%d]=");
        scanf("%d",&a[i]);
    }
}

void afisare_vector(int *a, int n){
    int i;
    printf("elementele vectorului sunt: \n")
    for(i=0;i<=n;i++){
            printf("a[%d]= ",i,a[i]);
    }
}

//linked list :D
#include <stdio.h>
#include <stdlib.h>
#include "function.h"
struct node {
    int inf;
    struct node *next;
};

void dispay_list(struct node *head){

    if(head->next!=NULL){
        struct node* current=head;
        do{
            current=current->next;
            printf("%d",current->inf);
        } while(current->next != NULL);
        printf("\n");
    }
    else
        printf("the list is empty");
}

void push_first(struct node *head, int val){
    struct node *nou;
    nou=(struct node*)malloc(sizeof (struct node));
    nou -> inf=val;
    nou -> next = head -> next;
    head -> next= nou;
}

void push_last(struct node *head, int val){
    struct node *nou;
    struct node *it=head;
    nou =(struct node*)malloc(sizeof(struct node) );
    while(it->next !=NULL)
            it=it->next;
    nou->inf=val;
    it->next= nou;
    nou-> next =NULL;
}

int rem_first(struct node *head){
    struct node *del;
    int value;
    del= head->next;
    value= del->inf;
    head->next=del->next;
    free(del);
    printf("valoarea elementului sters este %d\n", value);

}

void rem_last(struct node *head){
    struct node *it, *del;
    int value;
    it=head;
    while(it->next->next != NULL)
        it= it->next;
    del=it->next;
    value=del->inf;
    del->next=NULL;
    free(del);
    it->next=NULL;
    printf("valoarea stearsa este %d\n",value);
}

//mergesort

void merge(int *arr, int left, int right,int middle)
{
    int nr_elem1, nr_elem2;
    middle=(left+right)/2;
    nr_elem1=middle - left+1;       //numarul deelemente din prima jumatate a vectorului
    nr_elem2=right- middle;         //numarul de elemente di a doua jumatate a vectorului initial

    int left_a[nr_elem1], right_a[nr_elem2];

    int i=0,j,k;

    for(i=0;i<nr_elem1;i++)
        left_a[i] = arr[left+i];

    for(j=0;j<nr_elem2;j++)
        right_a[j] = arr[ middle+1+j ];

    i=0;
    j=0;
    k=left;

    while(i < nr_elem1 && j <nr_elem2){
        if(left_a[i]<=right_a[j]){
            arr[k]=left_a[i];
            i++;
        }
        else{
            arr[k]=right_a[j];
            j++;
        }
        k++;
    }

    while(i < nr_elem1){          //verificam daca mai exista elemente in left_a si le scriem in arr
        arr[k]= left_a[i];
        i++;
        k++;
    }

    while(j < nr_elem2){
        arr[k]=right_a[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr,int left, int right){
    int middle;
    if(left<right){
            middle=(left+right)/2;
            merge_sort(arr,left,middle);
            merge_sort(arr,middle+1,right);

            merge(arr,left,right, middle);
    }
}

