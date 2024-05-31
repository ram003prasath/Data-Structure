#include<stdio.h>
#include<stdlib.h>
#define max 10

int arr[max],n,i;

void create()
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
		arr[i]=ele;
	}
}

void insert(int ele,int pos)
{
	if(pos>max-2 || pos<0)
	{
		printf("\nInvalid Position");
		return;
	}
	for(i=n;i>pos;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[pos]=ele;
	n++;
}

void delete(int pos)
{
	if(pos>max-1 || pos<0)
	{
		printf("\nInvalid position");
		return;
	}
	for(i=pos;i<n;i++)
	{
		arr[i]=arr[i+1];
	}
	n--;
}

void display()
{
	printf("\nElements in your list: ");
	for(i=0;i<max;i++)
	{
		printf("%d\t",arr[i]);
	}
}

void main()
{
	int ch,num,ele,pos;
	while(ch!=5)
	{
		printf("\n\t\tMAIN MENU\n1. Create\n2. Insert\n3. Delete\n4. display\n5. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter no. of elements: ");
				scanf("%d",&n);
				create();
				break;
			case 2:
				printf("Enter position: ");
				scanf("%d",&pos);
				printf("Enter element to be inserted: ");
				scanf("%d",&ele);
				insert(ele,pos);
				break;
			case 3:
				printf("Enter position to be delected: ");
				scanf("%d",&pos);
				delete(pos);
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
