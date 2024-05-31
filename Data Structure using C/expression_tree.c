#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
	char data;
	struct node *lc;
	struct node *rc;
};
char prede[10];
int j=0;
char exper[10];
struct node *stack[10];
int top=-1;
struct node *root=NULL;

void push(struct node *data)
{
	if(top<9)
	{
		top=top+1;
		stack[top]=data;
	}
	else
	{
		printf("\n Stack Overflow");
	}
}

struct node* pop()
{
	return stack[top--];
	free(stack[top]);
}

struct node* createnode(char data)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->lc=NULL;
	newnode->rc=NULL;
	return newnode;
}

void operand(char alpha)
{
	struct node *temp;
	temp=createnode(alpha);
	push(temp);
}

void operator(char oper)
{
	struct node *t1,*t2;
	t2=pop();
	t1=pop();
	root=createnode(oper);
	root->lc=t1;
	root->rc=t2;
	push(root);
}

struct node* preorder(struct node *root)
{
	if(root==NULL) return 0;
	printf("%c",root->data);
	preorder(root->lc);
	preorder(root->rc);
} 	

struct node* inorder(struct node *root)
{
	if(root==NULL) return 0;
	inorder(root->lc);
	prede[j]=root->data;
	printf("%c",prede[j++]);
	inorder(root->rc);
} 

void main()
{
	int i=0;
	char ch='y';
	printf("\nEnter any postfix expression: ");
	scanf("%s",exper);
	while(exper[i]!='\0')
	{
		if(isalpha(exper[i])!=0)
		{
			operand(exper[i]);
		}
		else
		{
			operator(exper[i]);
		}
		i++;
	}
	printf("\n\nPreorder traversing : ");
	preorder(root);
	printf("\n\nInorder traversing : ");
	inorder(root);
}
