#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10

struct node
{
    char data[10];
    struct node *next;
    struct node *adj;
    int weight;
    char visited;
};

struct node *head = NULL;
struct node *stack[size];
int top=-1;

struct node *createnode(char name[10], int weight)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->data, name);
    newnode->adj = NULL;
    newnode->next = NULL;
    newnode->weight = weight;
    newnode->visited='f';
    return newnode;
}

int check(char name[10])
{
    int f = 0;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->data, name) == 0)
        {
            f = 1;
            break;
        }
        temp = temp->next;
    }
    if (f == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void create_vertex(char name[10])
{
    struct node *temp;
    if (check(name) == 1)
    {
        printf("\nVertex already exists");
        return;
    }
    if (head == NULL)
    {
        head = createnode(name, 0);
        printf("\nVertex created");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createnode(name, 0);
        printf("\nVertex created");
    }
}

void add_edge(char src[10], char des[10], int weight)
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nGraph is empty.");
		return;
	}
	if((check(src)==1)&&(check(des)==1))
	{
		temp=head;
		while(temp!=NULL)
		{
			if(strcmp(temp->data,src)==0)
			{
				while(temp->adj!=NULL)
				{
					temp=temp->adj;
				}
				temp->adj=createnode(des,weight);
				break;
			}
			temp=temp->next;
		}
	}
	else
	{
		printf("\nEither source or destination is not found.");
	}
}

struct node *get(struct node *ptr)
{
	struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->data, ptr->data) == 0)
        {
    		return temp;
        }
        temp = temp->next;
    }
}

void push(struct node *temp)
{
	if(temp->visited=='f')
	{
		temp=get(temp);
		stack[++top]=temp;
	}
}

struct node *pop()
{
	struct node *temp;
	temp=stack[top];
	top=top-1;
	return temp;
}

void dfs(struct node *temp)
{
	struct node *ptr;
	push(temp);
	while(top>=0)
	{
		ptr=pop();
		if(ptr->visited=='f')
		{
			printf("%s",ptr->data);
			ptr->visited='t';
			while(ptr->adj!=NULL)
			{
				ptr=ptr->adj;
				push(ptr);
			}
		}
	}
}

void display()
{
    struct node *temp, *ptr;
    printf("\nElements in graph are: ");
    temp = head;
    while (temp != NULL)
    {
        printf("\n%s", temp->data);
        ptr = temp->adj;
        while (ptr != NULL)
        {
            printf("-(%d)->%s", ptr->weight, ptr->data);
            ptr = ptr->adj;
        }
        temp = temp->next;
    }
}

void main()
{
    int ch, weight;
    char src[10], des[10], name[10];
    while (1)
    {
        printf("\n\n\tMAIN MENU\n1. Create vertex\n2. Create edge\n3. Display\n4. Depth First Search\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter vertex name: ");
            scanf("%s", name);
            create_vertex(name);
            break;
        case 2:
            printf("\nEnter source name: ");
            scanf("%s", src);
            printf("\nEnter destination name: ");
            scanf("%s", des);
            printf("\nEnter edge weight: ");
            scanf("%d", &weight);
            add_edge(src, des, weight);
            break;
        case 3:
            display();
            break;
        case 4:
        	dfs(head);
        	break;
        case 5:
            exit(0);
        default:
            printf("\nEnter valid input.");
            break;
        }
    }
}
