#include <stdio.h>
int min(int a[],int k,int n)
{
    int j,loc,min;
    min=a[k];
    loc=k;
    for(j=k+1;j<n;j++)
    {
        if(min>a[j])
        {
            min=a[j];
            loc=j;
        }
    }
    return (loc);
}

int main()
{
    int a[15],i,n,loc,temp;
    printf("\nEnter no. of elements: ");
    scanf("%d",&n);
    printf("\n enter elements of list\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        loc=min(a,i,n);
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
    printf("\n Sorted list is \n");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
    return 0;

}