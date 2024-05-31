#include <stdio.h>
#include<stdlib.h>
#define MAX_NODES 50

int graph[MAX_NODES][MAX_NODES];
int i,j;

void addEdge(int source, int destination) {
    if (source >= 0 && source < MAX_NODES && destination >= 0 && destination < MAX_NODES) {
        graph[source][destination] = 1;
    } else {
        printf("Invalid node indices.\n");
    }
}

void removeEdge(int source, int destination) {
    if (source >= 0 && source < MAX_NODES && destination >= 0 && destination < MAX_NODES) {
        graph[source][destination] = 0;
    } else {
        printf("Invalid node indices.\n");
    }
}

void outdegree(int node)
{
	int count=0;
	if(node < 0 && node > MAX_NODES )
	{
		printf("\nOut of range");
	}
	else
	{
		for (j = 0; j < MAX_NODES;j++)
		{
			if(graph[node][j]!=0)
			{
				count+=1;
			}	
		}
		printf("\nOut degree of the node %d is %d",node,count);
	}
}

void indegree(int node)
{
	int count=0;
	if(node < 0 && node > MAX_NODES )
	{
		printf("\nOut of range");
	}
	else
	{
		for (i = 0; i < MAX_NODES;i++)
		{
			if(graph[i][node]!=0)
			{
				count+=1;
			}
		}
		printf("\nIn degree of the node %d is %d",node,count);
	}
}

void printGraph(int max) {
	max+=1;
    printf("Graph Matrix:\n");
	printf("  ");
    for(i=0;i<max;i++)
    {
    	printf("%d ",i);
    }
    printf("\n---------");
    for(i=0;i<max;i++)
    {
    	printf("-");
    }
    printf("\n");
    for (i = 0; i < max;i++) {
    printf("%d|",i);
        for (j = 0; j < max;j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void main() {
	int ch,src,des,max=0;
	for (i = 0; i < MAX_NODES; i++) 
	{
       for (j = 0; j < MAX_NODES; j++) 
	   {
           graph[i][j] = 0;
       }
   }
	while(ch!=6)
	{
		printf("\n\t\tMENU\n1. Insert\n2. Delete\n3. Display\n4. In degree\n5. Out degree\n6. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the source vertex: ");
				scanf("%d",&src);
				printf("\nEnter the destination vertex: ");
				scanf("%d",&des);
				
				if(src>max)
				{
					max=src;
				}
				if(des>max)
				{
					max=des;
				}
				addEdge(src,des);
				break;
			case 2:
				printf("\nEnter the source vertex: ");
				scanf("%d",&src);
				printf("\nEnter the destination vertex: ");
				scanf("%d",&des);
				removeEdge(src,des);
				break;
			case 3:
				printGraph(max);
				break;
			case 4:
				printf("\nEnter the vertex: ");
				scanf("%d",&src);
				indegree(src);
				break;
			case 5:
				printf("\nEnter the vertex: ");
				scanf("%d",&src);
				outdegree(src);
				break;
			case 6:
				exit(0);
			default:
				printf("\nEnter valid input");
		}
	}
}
