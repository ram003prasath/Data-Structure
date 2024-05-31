#include<stdio.h>
#include<stdlib.h>
void display();
void insertatbag();
void insert();

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;

void insertatbeg()
{
	int item,n;
	printf("\nEnter the number of elements to be added:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		struct node *ptr;
		ptr=(struct node *)malloc(sizeof(struct node *));
		printf("\nEnter data:");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=head;
		head=ptr;
	}
	display();
}
void insertatend()
{
	int n,data;
	printf("\nEnter the number of elements to be added:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		struct node *ptr,*temp;
		ptr=(struct node *)malloc(sizeof(struct node *));
		printf("Enter data:");
		scanf("%d",&data);
		ptr->data=data;
		if(head==NULL)
		{
			ptr->next=NULL;
			head=ptr;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=NULL;	
		}	
	}
	display();
}

void insert()
{
	int loc,data;
	struct node *ptr,*temp;
	ptr=(struct node *)malloc(sizeof(struct node *));
	printf("\nEnter data:");
	scanf("%d",&data);
	ptr->data=data;
	printf("\nEnter the location you want to insert the data:");
	scanf("%d",&loc);
	temp=head;
	for(int i=0;i<loc-1;i++)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			printf("\nCan't insert");
		}
	}
	ptr->next=temp->next;
	temp->next=ptr;
	display();
}

void deletebeg()
{
	if(head==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		struct node *ptr;
		ptr=head;
		head=ptr->next;
		free(ptr);
		display();
	}
}

void deleteend()
{
	struct node *ptr,*temp;
	ptr=head;
	if(head==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		if(head->next==NULL)
		{
			head=NULL;
			free(head);
			display();
		}
		else
		{
			while(ptr->next!=NULL)
			{
				temp=ptr;
				ptr=ptr->next;
			}
			temp->next=NULL;
			free(ptr);
			display();
		}
	}
}

void deletepos()
{
	int pos;
	struct node *ptr,*temp;
	if(head==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		temp=head;
		printf("\nEnter the position to be deleted:");
		scanf("%d",&pos);
		for(int i=0;i<pos-1;i++)
		{
			temp=temp->next;
		}
		ptr=temp->next;
		temp->next=ptr->next;
		free(ptr);
		display();
	}
}

void search()
{
	int data,i=0;
	struct node *temp;
	printf("\nEnter the data to be searched:");
	scanf("%d",&data);
	temp=head;
	while(temp->next!=NULL)
	{
		if(temp->data==data)
		{
			printf("\nData found at the index: %d",i);
			return;
		}
		temp=temp->next;
		i++;	
	}
	printf("\nData not found");
}

void display()
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("\nLinked list elements are:");
			printf(" %d ",temp->data);
			temp=temp->next;
		}
	}
}

void main()
{
	
	int choice;  
    while(choice != 9)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice:");         
        scanf(" %d",&choice);  
        switch(choice)  
        {  
            case 1:  
            	insertatbeg();      
            	break;  
            case 2:  
            	insertatend();         
            	break;  
            case 3:  
            	insert();       
            	break;  
            case 4:  
            	deletebeg();       
            	break;  
            case 5:  
            	deleteend();        
            	break;  
            case 6:  
            	deletepos();          
            	break;  
            case 7:  
            	search();         
            	break;  
            case 8:  
            	display();        
            	break;  
            case 9:  
            	exit(0);  
            	break;  
            default:  
            	printf("\nPlease enter valid choice..");  
            	break;
        }  
    }
}
