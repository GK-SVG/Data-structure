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

void insertnodelast()
{
    struct node *temp,*t;
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
        while (t->next!=start)
            t=t->next;
        start->prev=temp;
        t->next=temp;
        temp->next=start;
        temp->prev=t;
    }
}

void insertspenode()
{
  struct node *temp,*t;
  int i=1,pos;
  printf("\nEnter position: ");
  scanf("%d",&pos);
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
        while(i<pos-1)
        {
            t=t->next;
            i++;
        }
        if(pos==1)
        {
            while(t->next!=start)
                t=t->next;
            temp->next=start;
            temp->prev=t;
            t->next=temp;
            start->prev=temp;
            start=temp;
        }
        else
        {
            temp->next=t->next;
            temp->prev=t;
            t->next=temp;
        }
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
      if(temp==start)
      {
          start=NULL;
          free(temp);
      }
      else
      {
          start = t->next;
          start->prev = temp;
          temp->next = start;
          free(t);
      }
    }
}

void deletenodelast()
{
    struct node *temp,*t;
    if(start==NULL)
        printf("\n LIst is empty");
    else
    {
        temp=start;
        while(temp->next!=start)
        {
            t=temp;
            temp=temp->next;
        }
        if(temp==start)
        {
            start=NULL;
            free(temp);
        }
        else
        {
            t->next=start;
            start->prev=t;
            free(temp);
        }

    }
}

void deletespenode()
{
    struct  node *temp,*t;
    int i=1,pos;
    printf("\n Enter position of deletion: ");
    scanf("%d",&pos);
    if(start==NULL)
        printf("\n List is empty");
    else
    {
        temp=start;
        while(i<pos-1)
        {
            t=temp;
            temp=temp->next;
            i++;
        }
        if(temp==start && temp->next==start)
        {
                start=NULL;
                free(temp);
        }
        if(temp->next==start)
        {

        }
        if(temp!=start && temp->next!=start)
        {
            t->next = temp->next;
            temp->next->prev = t;
            free(temp);
        }
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
        while(temp!=start)
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
    printf("\n3.Insert specified Node");
    printf("\n4.Delete First Node");
    printf("\n5.Delete Last Node");
    printf("\n6.Delete specified Node");
    printf("\n7.display");
    printf("\n Enter choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            insertnode1st();
            break;
        case 2:
            insertnodelast();
            break;
        case 3:
            insertspenode();
            break;
        case 4:
            deletenode1st();
            break;
        case 5:
            deletenodelast();
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

