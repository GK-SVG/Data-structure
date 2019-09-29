#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *start=NULL;

struct node *createlist()
{
    struct node *n;
    n= (struct node*) malloc(sizeof(struct node));
    return n;
}

void insetnode()
{
    struct node *temp, *t;
    temp=createlist();
    printf("\n enter the data in list : ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        t=start;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }
}

void insertnode1st()
{
    struct node *temp;
    if(start==NULL)
    {
        temp=createlist();
        printf("\n enter the data in list : ");
        scanf("%d",&temp->info);
        temp->link=NULL;
        start=temp;
    }
    else
    {
        temp=createlist();
        printf("\n enter the data in list : ");
        scanf("%d",&temp->info);
        temp->link=start;
        start=temp;
    }
}

void insertspenode()
{
    struct node *temp, *t,*r;
    int n, i=1;
    temp=start;
    printf("\n enter insertion position : ");
    scanf("%d",&n);
    t=createlist();
    printf("\n enter insertion data : ");
    scanf("%d",&t->info);
    while (i<n-1)
    {
        temp=temp->link;
        i++;
    }
    r=temp->link;
    temp->link=t;
    t->link=r;
}

void deleteBegNode()
{
    struct node *del;
    if(start==NULL)
        printf("\n stack is empty ");
    else
    {
        del=start;
        start=start->link;
        free(del);
    }
}

void deleteLastNode()
{
    struct node *prevnode, *temp;
    if(start==NULL)
        printf("\n stack is empty ");
    else
    {
        temp=start;
        while(temp->link!=NULL)
        {
            prevnode=temp;
            temp=temp->link;
        }
        if(temp==start)
            start=NULL;
        else
            prevnode->link=NULL;
        free(temp);
    }
}

void deletespeNode()
{
    struct node *temp,*next;
    int n,i=1;
    temp=start;
    printf("\n enter node position for deletion : ");
    scanf("%d",&n);
    while(i<n-1)
    {
        temp=temp->link;
        i++;
    }
    next=temp->link;
    temp->link=next->link;
    free(next);
}

void displaylist()
{
    struct node *t;
    if(start==NULL)
        printf("\n stack is empty ");
    else
    {
        t=start;
        while(t!=NULL)
        {
            printf("\n%d",t->info);
            t=t->link;
        }
    }
}

void menu()
{
    int choice;
    printf("\n1.Insert Node at start");
    printf("\n2.Insert Node at last ");
    printf("\n3Insert a specified Node");
    printf("\n4.Delete First Node");
    printf("\n5.Delete Last Node");
    printf("\n6.Delete specified Node");
    printf("\n7.Display List");
    printf("\n8.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            insertnode1st();
            break;
        case 2:
            insetnode();
            break;
        case 3:
            insertspenode();
            break;
        case 4:
            deleteBegNode();
            break;
        case 5:
            deleteLastNode();
            break;
        case 6:
            deletespeNode();
            break;
        case 7:
            displaylist();
            break;
        case 8:
            exit(0);
        default:
            printf("\n invalid input ");
    }
}

int main()
{
    int a=1;
    while(a)
    {
        menu();
        printf("\n Do you want to contineu(0/1) : ");
        scanf("%d",&a);
    }
    return 0;
}