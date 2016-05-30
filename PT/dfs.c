
void main()
{
 int i,j,nrNoduri;
 FILE *test;
 test = fopen("test.in.txt","r");
 fscanf(test,"%d",&nrNoduri);
 printf("\n Numarul de muchii este:  %d ", nrNoduri);
 citire(nrNoduri, test);
 dfs(1,nrNoduri);
 printf("\n");

}
