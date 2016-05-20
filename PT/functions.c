#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "functii.h"

void cit_vector(int n, int *a){
    int i;
    for(i=0;i<n;i++){
        printf("a[%d]=");
        scanf("%d",&a[i]);
    }
}

void afisare_vector(int *a, int n){
    int i;
    printf("elementele sunt:");
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
}

//linked list :D
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
int rand(void);

void random_arr(int *arr,int n){
    int i=0;
    while(n > 0){
        arr[i] = rand() % 1000;
        i++;
        n--;
    }
}

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


//shell sort using gap sort
/* alegem un index, de unde sa incepem sortarea, am ales mijlocul*/
void shell(int *a, int n){
    int gap=n/2;
    int i, j, aux;
    while(gap > 0){
        for(i=0 ; i<n ; i++){
            j=i;
             aux= a[i];
             while(j >= gap && a[j- gap] > aux){
                a[j]= a[j- gap];
                j=j - gap;
             }
             a[j] = aux;
        }
        gap = gap/2;
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

// selection sort
// mai folosesc funtctia random_arr  si afisare_vector
void swap (int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void selection(int *a, int n){
    int i,j,imin;
    for(j=0 ;j< n-1 ; j++){
        imin=j;
        for(i= j+1 ; i<n ; i++){
            if(a[imin] > a[i])
                imin=i;
        }
    if(imin != j)
        swap(&a[j],&a[imin]);

        }
}

//insertion sort   folosesc functiile: afisare_vector, random_arr,swap;

void insertion(int *a,int n){
    int i,j;
    for(i=0; i<n ; i++){
        j=i;                                //
        while(j > 0 && a[j-1] > a[j]){
            swap(&a[j] , &a[j-1]);
            j--;
        }
    }
}

//shell sort
void shell(int *a, int n){
    int gap=n/2;
    int i, j, aux;
    while(gap > 0){
        for(i=0 ; i<n ; i++){
            j=i;
             aux= a[i];
             while(j >= gap && a[j- gap] > aux){
                a[j]= a[j- gap];
                j=j - gap;
             }
             a[j] = aux;
        }
        gap = gap/2;
    }
}
// heap sort
struct node {
    int data;
    struct node *left, *right
};

void insert(struct node *root, int value)
{
	if (value < root->data)
	{
		if (root->left == NULL)
		{
			struct node *temp;
			temp = (struct node*)malloc(sizeof(struct node));
			temp->data = value;
			temp->left = NULL;
			temp->right = NULL;
			root->left = temp;
		}
		else
			insert(root->left, value);
	}
	else
	{
		if (root->right == NULL)
		{
			struct node *n;
			n = (struct node*)malloc(sizeof(struct node));
			n->data = value;
			n->left = NULL;
			n->right = NULL;
			root->right = n;
		}
		else
			insert(root->right, value);
	}
}

void HeapSort(struct node *root)
{
	if (root->left != NULL)
		HeapSort(root->left);
	printf("%d ", root->data);
	if (root->right != NULL)
		HeapSort(root->right);
}

void ConstructHeap(int n,struct node *root)
{
	int val,i;
	for ( i = 1;i <= n-1;i++)
	{
		scanf("%d", &val);
		insert(root, val);
	}
}
int max(int x[], int n){
    int i, max = x[0];
    for(i=1;i<n;i++){
        if(x[i]>max){
            max = x[i];
        }
    }
    return max;
}
