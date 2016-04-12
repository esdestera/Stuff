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
