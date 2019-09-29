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
  printf("\n1.Insert Node at last ");
  printf("\n2.Delete First Node");
  printf("\n3.Delete Last Node");
  printf("\n4.Display List");
  printf("\n5.Exit");
  printf("\nEnter your choice: ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
        insetnode();
        break;
    case 2:
        deleteBegNode();
        break;
	case 3:
		deleteLastNode();
		break;
	case 4:
	    displaylist();
	    break;
	case 5:
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