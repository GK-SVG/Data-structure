#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct  node *prev, *next;
};

struct node *start=NULL;

void insertdata()
{
    struct  node *n;
    n= (struct node*) malloc(sizeof(struct node));
    printf("\n enter data in list : ");
    scanf("%d",&n->info);
    n->prev=NULL;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else
    {
        n->next=start;
        start->prev=n;
        start=n;
    }
}

void deletenode()
{
    struct  node *temp;
    temp=start;
    if(start==NULL)
     printf("\n list is empty");
    else
    {
        start=temp->next;
        start->prev=NULL;
        free(temp);
    }
}

void displaylist()
{
    struct  node *temp;
    if(start==NULL)
        printf("\n list is empty ");
    else
    {
        temp=start;
        while(temp!=NULL)
        {
            printf("\n%d",temp->info);
            temp=temp->next;
        }
    }
}

void menu()
{
    int ch;
    printf("\n1.Insert Node at start");
    printf("\n2.Delet");
    printf("\n3.display");
    printf("\n Enter choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            insertdata();
            break;
        case 2:
            deletenode();
            break;
        case 3:
            displaylist();
            break;
        default:
            printf("\n invalid input");
    }
}

int main()
{
    int a=1;
    while (a)
    {
        menu();
        printf("\n do want contineu(0/1): ");
        scanf("%d",&a);
    }
}
