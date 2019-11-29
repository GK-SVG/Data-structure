#include <stdlib.h>
#include<stdio.h>
#include <iostream>
int main()
{
    int n;
    printf("\n enter number of elements:");
    scanf("%d",&n);
    int *p=new int[n];
    printf("\n enter elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("\n entered valus is\n");
    for(int i=0;i<n;i++)
        printf("\t%d",p[i]);
    delete []p;
    return 0;
}