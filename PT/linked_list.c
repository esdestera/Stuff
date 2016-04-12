
#include "functii.h "
int main()
{
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;

    push_first(head,4);
    push_first(head,5);
    dispay_list(head);
    push_last(head,8);
    dispay_list(head);
    rem_first(head);
    rem_last(head);
    dispay_list(head);
    return 0;
}
