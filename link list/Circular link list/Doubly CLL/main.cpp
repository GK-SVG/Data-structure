#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct  node *prev, *next;
};

struct node *start=NULL;

void insertnode1st()
{
    struct  node *t,*temp;
    temp= (struct node*) malloc(sizeof(struct node));
    printf("\n enter data in list : ");
    scanf("%d",&temp->info);
    temp->prev=NULL;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        temp->prev=temp;
        temp->next=temp;
    }
    else
    {
        t=start;
        while(t->next!=start)
        {
            t=t->next;
        }
        t->next=temp;
        start->prev=temp;
        temp->next=start;
        temp->prev=t;
        start=temp;
    }
}

void deletenode1st()
{
    struct node *temp,*t;
    if(start==NULL)
        printf("\n List is empty");
    else
    {
      temp=start;
      t=start;
      while (temp->next!=start)
          temp=temp->next;
      start=t->next;
      start->prev=temp;
      temp->next=start;
      free(t);
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
        while(temp->next!=start)
        {
            printf("\n%d",temp->info);
            temp=temp->next;
        }
        printf("\n%d",temp->info);
    }
}

void menu()
{
    int ch;
    printf("\n1.Insert Node at start");
    printf("\n2.Delete First Node");
    printf("\n3.display");
    printf("\n Enter choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            insertnode1st();
            break;
        case 2:
            deletenode1st();
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
