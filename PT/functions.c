#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include<limits.h>
#include "functii.h"

int matrice[10][10], vizitat[10], nrMuchii;
int nrNoduri;
void cit_vector(int n, int *a){
    int i;
    for(i=0;i<n;i++){
        printf("a[%d]=", i);
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

int pop_first(struct node *head){
    struct node *del;
    int value;
    del= head->next;
    value= del->inf;
    head->next=del->next;
    free(del);
    return value;

}

int pop_last(struct node *head){
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
    return value;
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
// heap sort
struct nod {
    int data;
    struct nod *left, *right;
};

void insert(struct nod *root, int value){
	if (value < root->data)
	{
		if (root->left == NULL)
		{
			struct nod *temp;
			temp = (struct nod*)malloc(sizeof(struct nod));
			temp->data = value;
			temp->left = NULL;
			temp->right = NULL;
			root->left = temp;
		}
		else{
			insert(root->left, value);
		}
	}
	else
	{
		if (root->right == NULL)
		{
			struct nod *n;
			n = (struct nod*)malloc(sizeof(struct nod));
			n->data = value;
			n->left = NULL;
			n->right = NULL;
			root->right = n;
		}
		else{
			insert(root->right, value);
		}
	}
}

void HeapSort(struct nod *root){
	if (root->left != NULL){
		HeapSort(root->left);
	}
	printf("%d ", root->data);
	if (root->right != NULL){
		HeapSort(root->right);
	}
}

void createHeap(int n,struct nod *root){
	int val,i;
	for ( i = 1;i <= n-1;i++)
	{
		scanf("%d", &val);
		insert(root, val);
	}
}

/*DFS*/
void citire_cu_muchii(FILE *test){
    int i, j, source ,target;
    if (test == NULL) {
        printf("Error: Fisierul este gol.");
        exit(1);
    }

    for(i = 0; i< nrNoduri;i++){
        for(j=0;j<nrNoduri;j++){
            matrice[i][j] = 0;
            vizitat[i] = 0;
        }
    }
    for(i=0;i<nrMuchii;i++){
        fscanf(test,"%d %d",&source,&target);
        matrice[source][target] = 1 ;

    }
}

// DFS cu stiva
void dfs_stack (struct node *head, int nodStart){
    int i;
    push_first(head, nodStart);
    vizitat[nodStart] = 1;
    printf("%d  ",nodStart);
    nodStart = pop_first(head);
    for(i = 0; i < nrNoduri;i++){
        if(matrice[nodStart][i] == 1 && vizitat[i] == 0){
                vizitat[i] = 1;

                dfs_stack(head, i);
        }
    }
}

// dfs cu vectori;
void dfs_arr(int nodStart){
    int i;
    vizitat[nodStart] = 1;
    for(i=1;i<=nrNoduri;i++){
        if(matrice[nodStart][i] == 1 && vizitat[i] == 0){
            printf("\n %d->%d", nodStart, i);
            dfs_arr(i);
        }
    }
}


void citire( FILE *test){
    int i, j;
    if (test == NULL) {
        printf("Error: Fisierul este gol.");
        exit(1);
    }

    for(i=1;i<=nrNoduri;i++){
        vizitat[i]=0;
    }

    for(i=1;i<=nrNoduri;i++){
        for(j=1;j<=nrNoduri;j++){
            fscanf(test,"%d",&matrice[i][j]);
        }
    }
}
//bfs- corect????? cu cozi

void bfs(struct node *head, int nodStart){
    int i;
    push_last(head,nodStart);
    vizitat[nodStart] = 1;
    printf("%d ", nodStart);
    pop_first(head);
    for(i=0;i < nrNoduri;i++){
        if(matrice[nodStart][i] == 1 && vizitat[i] == 0){
            vizitat[i] = 1;
            bfs(head, i);
        }
    }

}



// rucsac
/*
struct obiect
{
    float gr,val,ef;//greutate, castig, raportul cat se ia din obiect
};

void citire_rucsac(float greutate, int n, struct obiect a[], FILE *f){

    int i;
    fscanf(f, "%d %f",&n, &greutate );
    for(i =1;i<=n;i++){
            fscanf(f ,"%f %f", &a[i].gr, &a[i].val);
            a[i].ef=0;//initial nu se foloseste obiectul
        }
}

void ordonare(int n, struct obiect a[])//ordonare dupa castig/greutate
{
    int i,j;
    struct obiect aux;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(a[i].val/a[i].gr < a[j].val/a[j].gr)
            {
                aux=a[i]; a[i]=a[j]; a[j]=aux;
            }
}

void afisare(int n, struct obiect a[])
{
    float c=0;
    int i;
    for(i=1;i<=n;i++)
        { printf("greutatea: %f \tvaloarea: %f \t eficienta: %f", a[i].gr, a[i].val, a[i].ef);
          c=c+a[i].val*a[i].ef;
        }
    printf("\n castig maxim: %f", c);
}

void greedy(float greutate, int n, struct obiect a[])
{
    struct obiect s[100];
    int i,k;
    float sp=0;
    k=0; i=1;
    while(sp < greutate){
        if(sp+a[i].gr <= greutate){
                sp = sp+a[i].gr;
                s[++k]=a[i];
                s[k].ef=1;//obiect intreg
        }
        else{
            s[++k]=a[i];
            s[k].ef=(greutate - sp)/a[i].gr;//obiect fractionat
            sp = greutate;
        }
        i++;
    }
    afisare(k,s);
}
*/

int MatrixChainOrder(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    // place parenthesis at different places between first
    // and last matrix, recursively calculate count of
    // multiplications for each parenthesis placement and
    // return the minimum count
    for (k = i; k <j; k++)
    {
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k+1, j) + p[i-1]*p[k]*p[j];

        if (count < min)
            min = count;
    }

    // Return minimum count
    return min;
}

// N QUEEN
#define N 4
void printSolution(int board[N][N]){
    int i;
    int j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf(" %d ", board[i][j]);
            }
        printf("\n");
    }
}

/* A utility function to check if a queen can
   be placed on board[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */
bool isSafe(int board[N][N], int row, int col){
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++){
        if (board[row][i]){
            return false;
        }
    }

    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--){
        if (board[i][j]){
            return false;
        }
    }
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

/* A recursive utility function to solve N
   Queen problem */

bool solveNQUtil(int board[N][N], int col){
    int  i;
    /* base case: If all queens are placed
      then return true */
    if (col >= N)
        printSolution(board);
        printf("\n");

    /* Consider this column and try placing
       this queen in all rows one by one */
    for (i = 0; i < N; i++){
        /* Check if queen can be placed on
          board[i][col] */
        if ( isSafe(board, i, col) ){
            /* Place this queen in board[i][col] */
            board[i][col] = 1;

            /* recur to place rest of the queens */
            if ( solveNQUtil(board, col + 1) ){
                printSolution(board);
	    }
            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }

     /* If queen can not be place in any row in
        this colum col  then return false */
    return false;
}

/* This function solves the N Queen problem using
   Backtracking. It mainly uses solveNQUtil() to
   solve the problem. It returns false if queens
   cannot be placed, otherwise return true and
   prints placement of queens in the form of 1s.
   Please note that there may be more than one
   solutions, this function prints one  of the
   feasible solutions.*/
bool solveNQ()
{
    int board[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if ( solveNQUtil(board, 0) == false )
    {
      printf("Solution does not exist");
      return false;
    }

    printSolution(board);
    return true;
}

//knapsack
int max(int a, int b) {
  if(a > b)
    return a;
  else
    return b;
}

// Returns the maximum value that can be put in a knapsack of capacity Weight
int knapSack(int weight, int wt[], int val[], int n)
{
   int i, j;
   int K[n+1][weight+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= weight; j++)
       {
           if (i==0 || j==0)
               K[i][j] = 0;
           else if (wt[i-1] <= j)
                 K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]);
           else
                 K[i][j] = K[i-1][j];
       }
   }

   return K[n][weight];
}

//numbers permutations
void permute(int *array,int i,int length) {
  if (length == i){
     afisare_vector(array,length);
     return;
  }
  int j = i;
  for (j = i; j < length; j++) {
     swap(array+i,array+j);
     permute(array,i+1,length);
     swap(array+i,array+j);
  }
  return;
}
