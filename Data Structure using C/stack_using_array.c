#include<stdio.h>
#include<stdlib.h>
#define max 10

int arr[max],n,num,top=-1,i;

void create(int n)
{
	int ele;
	if(n>max || n<0)
	{
		printf("\nMaximum size of list is 10");
		return;
	}
	for(i=0;i<n;i++)
	{
		printf("\nEnter element: ");
		scanf("%d",&ele);
		arr[++top]=ele;
	}
}

void push(int ele)
{
	if(top>9)
	{
		return;
	}
	arr[++top]=ele;
	n++;
}

void pop()
{
	if(n<0)
	{
		printf("Stack under flow");
	}
	arr[top--]=NULL;
	n--;
}

void display()
{
	printf("\nElements in your list: ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}

void main()
{
	int ch,num,ele;
	while(ch!=5)
	{
		printf("\n\t\tMAIN MENU\n1. Create\n2. Insert\n3. Delete\n4. display\n5. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter no. of elements: ");
				scanf("%d",&n);
				create(n);
				break;
			case 2:
				printf("Enter element to be inserted: ");
				scanf("%d",&ele);
				push(ele);
				break;
			case 3:
				pop();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid Input");
				break;
		}
	}
}
