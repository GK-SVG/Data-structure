#include <stdio.h>
int main()
{
    int a[15],i,n,j,temp;
    printf("\nEnter no. of elements: ");
    scanf("%d",&n);
    printf("\n enter elements of list\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
     temp=a[i];
     for(j=i-1;j>=0&&temp<a[j];j--)
         a[j + 1] = a[j];
     a[j + 1]=temp;

    }
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
    return 0;
}