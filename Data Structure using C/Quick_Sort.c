#include<stdio.h>
#include<stdlib.h>
#define size 20

int arr[size],num;

void swap(int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void display()
{
	int i;
	printf("\nSorted array:\n");
    for (i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }
}

void quick_sort(int low,int high)
{
    if (low<high)
    {
        int pivot=arr[low];
        int i=low+1;
        int j=high;

        while (i<=j)
        {
            while(i<=high&&arr[i]<pivot)
            {
                i++;
            }

            while (j>=low && arr[j]>pivot)
            {
                j--;
            }

            if (i<j)
            {
                swap(i,j);
            }
        }

        swap(low,j);

        quick_sort(low,j-1);
        quick_sort(j+1,high);
    }
}

void main()
{
    int i;
    printf("\nEnter no. of elements in array (<= 20): ");
    scanf("%d",&num);
    if (num>size||num<=0)
    {
        printf("\nInvalid input for array size. Exiting program.");
        exit(0);
    }
    for(i=0;i<num;i++)
    {
        printf("\nEnter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    quick_sort(0,num-1);
    display();
}
