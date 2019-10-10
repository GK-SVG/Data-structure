// C program to implement Bubble Sort on singly linked list
#include<stdio.h>
#include<stdlib.h>


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

void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort()
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void Binarysearch()
{
    struct  Node *temp;
    int l=0,i;
    n=n-1;
    int m;
    printf("\nEnter searching element : ");
    scanf("%d",&i);
    while (l<=n)
    {
        temp=start;
        m=(l+n)/2;
        for(int j=0;j<m;j++)
        {
            temp=temp->next;
        }
        if (temp->data == i)
        {
          printf("\nsearch successful , at index %d",m);
            return;;
        }
        else
            if(temp->data<i)
            {
                l=m+1;
            }
            else
            {
                n=m-1;
            }
    }
    printf("\nsearching unsuccessful");
}

int main()
{
    createlist();
    printf("\nInserted list is bellow");
    printList();
    bubbleSort();
    printf("\nSorted list is bellow");
    printList();
    Binarysearch();
    return  0;
}




