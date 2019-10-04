#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *start=NULL;

void insertnodelast()
{
    struct node *temp,*t;
    temp=(struct node*) malloc(sizeof(struct node));
    printf("\n Enter data: ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(start==NULL)
    {
        start=temp;
        temp->link=start;
    }
    else
    {
        t=start;
        while(t->link!=start)
        {
            t=t->link;
        }
        t->link=temp;
        temp->link=start;
    }
}

void insertnodefirst()
{
    struct node *temp,*t;
    temp=(struct node*) malloc(sizeof(struct node));
    printf("\n Enter data: ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(start==NULL)
    {
        start=temp;
        temp->link=start;
    }
    else
    {
        t=start;
        while (t->link!=start)
            t=t->link;
        temp->link=start;
        start=temp;
        t->link=temp;
    }

}

void insertspenode()
{
    struct node *temp,*t;
    int pos,i=1;
    printf("\n Enter position: ");
    scanf("%d",&pos);
    temp=(struct node*) malloc(sizeof(struct node));
    printf("\n Enter data: ");
    scanf("%d",&temp->info);
    t=start;
    while (i<pos-1)
    {
        t=t->link;
        i++;
    }
    if(pos==1)
    {
        while (t->link!=start)
            t=t->link;
        temp->link=start;
        start=temp;
        t->link=start;
    }
    else
    {
        temp->link = t->link;
        t->link = temp;
    }

}

void deletenodelast()
{
    struct node *temp,*pre;
    if(start==NULL)
        printf("\n List is empty ");
    else
    {
        temp=start;
        while (temp->link!=start)
        {
            pre=temp;
            temp=temp->link;
        }
        if(temp!=start)
        {
            pre->link=start;
            free(temp);
        }
        else
        {
            free(temp);
            start=NULL;
        }
    }
}

void deletenode1st()
{
    struct node *temp,*t;
    if(start==NULL)
        printf("\n List is empty ");
    else
    {
       temp=start;
       t=start;
       while (t->link!=start)
           t=t->link;
       if(t!=start)
       {
           t->link = temp->link;
           start = temp->link;
           free(temp);
       }
       else
       {
           free(temp);
           start=NULL;
       }
    }
}

void deletespenode()
{
    struct node *temp,*next;
    int i=1,pos;
    printf("\n Enter position of deletion: ");
    scanf("%d",&pos);
    if(start==NULL)
        printf("\n List is empty");
    else {
        temp = start;
        while (i < pos - 1)
        {
            temp = temp->link;
            i++;
        }
        if (temp != start || temp->link!=start)
        {
            if(temp==start)
            {
                while(next->link!=start)
                    next=next->link;
                start=temp->link;
                next->link=start;
                free(temp);
            }
            else
            {
                next = temp->link;
                temp->link = next->link;
                free(next);
            }
        }
        else
        {
            free(temp);
            start=NULL;
        }
    }
}
void display()
{
    struct node *temp;
    if(start==NULL)
        printf("\n List is empty ");
    else
    {
        temp=start;
        while (temp->link!=start)
        {
            printf("\n%d",temp->info);
            temp=temp->link;
        }
        printf("\n%d",temp->info);
    }
}

void menu()
{
    int choice;
    printf("\n1.Insert Node at last");
    printf("\n2.Tnsert Node at first");
    printf("\n3.Insert Specific Node");
    printf("\n4.Delete Last Node");
    printf("\n5.Delete First Node");
    printf("\n6.Delete specific Node");
    printf("\n7.Display");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            insertnodelast();
            break;
        case 2:
            insertnodefirst();
            break;
        case 3:
            insertspenode();
            break;
        case 4:
            deletenodelast();
            break;
        case 5:
            deletenode1st();
            break;
        case 6:
            deletespenode();
            break;
        case 7:
            display();
            break;
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
