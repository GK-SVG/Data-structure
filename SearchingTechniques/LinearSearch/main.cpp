//linear searching source code writtwn by GAUTAM777(GK)
#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct  node *start=NULL;

void createlist()
{
    struct  node *temp,*t;
    int n,option=1;
    printf("\nHow many value You want to enter : ");
    scanf("%d",&n);
    while(option<=n)
    {
        temp = (struct node *) malloc(sizeof(struct node));
        printf("\n Enter data in list: ");
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            t = start;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = temp;
        }
        option++;
    }
}

void search()
{
    struct node *temp;
    int a,flag=1;
    printf("\n Enter data which you want to search : ");
    scanf("%d",&a);
    temp=start;
    while (temp->next!=NULL)
    {
        if (temp->data==a)
        {
            flag++;
        }
        temp=temp->next;
    }
    if (temp->data==a)
    {
        flag++;
    }
    if(flag>1)
        printf("\n searching succesfull");
    else
        printf("\n data not found");

}

int main()
{
    int i,a=1;
    while (a)
    {
        printf("\n1.Creatlist");
        printf("\n2.Search");
        printf("\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &i);
        switch (i) {
            case 1:
                createlist();
                break;
            case 2:
                search();
                break;
            case 3:
                exit(0);
        }
        printf("\n do want search (0/1): ");
        scanf("%d",&a);
    }
    return 0;

}
