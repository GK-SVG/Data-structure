// buble sort programe empliment with array Written by GAUTAM777
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                /*if element is greater then swap it by swap funtion*/
                swap(&arr[j], &arr[j+1]);
    for(i=0;i<10;i++)
        printf("\t %d",arr[i]);
}

int main()
{
    int a[10],i;
    printf("\nEnter the value of list \n ");
    for(i=0;i<10;i++)
    scanf("%d",&a[i]);
    bubbleSort(a,10);
 /*   for (i = 0; i < 10-1; i++)
        for (j = 0; j < 10-i-1; j++)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
    printf("\n sorted list is bellow \n\n");
    for(i=0;i<10;i++)
    printf("\t %d",a[i]);*/
    return 0;

}
