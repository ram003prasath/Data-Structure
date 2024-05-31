#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[50], n = 0;

void display() 
{
    int i;
    if (n == 0) 
    {
        printf("\nHeap is empty.");
    } 
    else 
    {
        printf("\nElements in heap: ");
        for (i = 0; i <= n; i++) 
        {
            printf("%d:%d\t", i, arr[i]);
        }
    }
}

void shift_up(int i) 
{
    int temp, j;
    j = floor(i / 2);
    if ((j >= 0) && (arr[i] > arr[j])) 
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        shift_up(j);
    }
}

void insert(int data) 
{
    if (n < 50) 
    {
        n = n + 1;
        arr[n] = data;
        shift_up(n);
    } 
    else 
    {
        printf("Heap is full. Cannot insert more elements.\n");
    }
    display();
}

int max(int a,int b)
{
    if(arr[a]>arr[b])
    {
        return a;
    }
    else
    {
        return b;
    }
}

void shift_down(int i)
{
    int j,temp;
    j = max(2*i, (2*i)+1);
    if((j <= n) && (arr[i] < arr[j]))
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        shift_down(j);
    }
}

int extract(int f) 
{
    int max = arr[0];
    arr[0] = arr[n];
    n = n - 1;
    shift_down(0);
    if(f==0)
    {
    	printf("\nMaximum element %d is extracted.", max);
    }
    return max;
}

void heap_sort()
{
	printf("\nHeap Sort: ");
    int i, temp;
    for (i = n; i > 0; i--) 
    {
        printf("%d\t",extract(1));
    }
}

int main() 
{
    int ch, data,temp;

    printf("\nEnter the first number: ");
    scanf("%d", &data);
    arr[0] = data;

    while (1) 
    {
        printf("\n\tMAX HEAP\n1. Insert\n2. Extract MAX\n3. Sort\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                printf("\nEnter any number: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                temp=extract(0);
                break;
            case 3:
                heap_sort();
                display(); 
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid input");
                break;
        }
    }
    return 0;
}
