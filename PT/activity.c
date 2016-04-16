#include <stdio.h>
#include <stdlib.h>
 struct activitate{
        char nume[20];
        int start, stop;
};
int citire_structura(struct activitate *act,int n){
    int i;
    for(i=1;i<=n;i++){
        printf("activitatea %d :\n",i);
        printf("nume[%d]=" ,i);
        scanf("%s",&act[i].nume);
        printf("start[%d]= ",i);
        scanf("%d",&act[i].start);
        printf("stop[%d]= ",i);
        scanf("%d",&act[i].stop);
    }
}

void greedy(struct activitate *act, int n){
    int c=1,i;
    i=1;
    printf("%s\n",act[c].nume);
    for(i=2;i<=n;i++)
        if(act[i].start >= act[c].stop){
                printf("%s\n",act[i].nume);
                c=i;
            }

}
int main()
{
    int n, i,c=1;
    struct activitate act[20];
    printf("n=");
    scanf("%d",&n);
    citire_structura(act,n);
    greedy(act,n);


}
