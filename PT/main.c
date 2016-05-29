
int main()
{
    FILE *test;
    test = fopen("test.in.txt","r");
    int nrMuchii, nrNoduri;
    struct node *head = (struct node*)malloc(sizeof (struct node));
    fscanf(test,"%d %d",&nrNoduri,&nrMuchii);
    head->next = NULL;
    citire(nrNoduri, nrMuchii, test);
    dfs(head, 1);
    return 0;

}
