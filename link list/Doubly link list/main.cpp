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

void insertdataend()
{
    struct node *n,*temp;
    n= (struct node*) malloc(sizeof(struct node));
    printf("\n enter data in list : ");
    scanf("%d",&n->info);
    n->prev=NULL;
    n->next=NULL;
    if (start==NULL)
        start=n;
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }

}

void insertspenode()
{
    struct  node *temp,*t,*r;
    int n,i=1;
    printf("\n Enter insertion position : ");
    scanf("%d",&n);
    t=(struct node*) malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d",&t->info);
    t->prev=NULL;
    t->next=NULL;
    temp=start;
    while(i<n-1)
    {
        temp=temp->next;
        i++;
    }
    r=temp->next;
    t->next=temp->next;
    t->prev=temp;
    temp->next=t;
    r->prev=t;
}

void deletelastnode()
{
    struct node *temp,*pre;
    if(start==NULL)
        printf("\n list is empty");
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            pre=temp;
            temp=temp->next;
        }
        if(temp==start)
            start=NULL;
        else
        {
            pre->next=NULL;
            free(temp);
        }
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

void deletespenode()
{
   struct  node *temp,*pre;
   int i=1,pos;
   printf("\n enter position to be deleted : ");
   scanf("%d",&pos);
   temp=start;
   while (i<pos)
    {
        pre=temp;
        temp=temp->next;
        i++;
    }
   pre->next=temp->next;
   temp->next->prev=pre;
   free(temp);
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
    printf("\n2.Insert Node at last");
    printf("\n3.Insert Node atspecific position");
    printf("\n4.Delet");
    printf("\n5.Delet Last Node");
    printf("\n6.Delete specified node");
    printf("\n7.display");
    printf("\n Enter choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            insertdata();
            break;
        case 2:
            insertdataend();
            break;
        case 3:
            insertspenode();
            break;
        case 4:
            deletenode();
            break;
        case 5:
            deletelastnode();
            break;
        case 6:
            deletespenode();
            break;
        case 7:
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
