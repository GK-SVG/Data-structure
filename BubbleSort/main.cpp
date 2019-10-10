//bubble sort programme written by GAUTAM KUMAR
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct  Node *start=NULL;
int n;

void createlist()
{
    struct  Node *temp,*t;
    int option=1;
    printf("\nHow many value You want to enter : ");
    scanf("%d",&n);
    while(option<=n)
    {
        temp = (struct Node *) malloc(sizeof(struct Node));
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

void printList()
{
    struct Node *temp = start;
    printf("\n");
    while (temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void swap(struct Node *temp, struct Node *t)
{
    int a = temp->data;
    temp->data = t->data;
    t->data = a;
}

void bubblesort()
{
    struct Node *temp, *t=NULL;

    int swapped,i;
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        temp = start;

        while (temp->next != t)
        {
            if (temp->data > temp->next->data)
            {
                swap(temp, temp->next);
                swapped = 1;
            }
            temp = temp->next;
        }
        t = temp;
    }
    while (swapped);
}

int main()
{
    createlist();
    printf("\nInserted list is bellow");
    printList();
    bubblesort();
    printf("\nSorted list is bellow");
    printList();
    return  0;
}
