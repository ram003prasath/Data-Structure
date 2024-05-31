#include <stdio.h>
#include<stdlib.h>
#define MAX_NODES 10

int graph[MAX_NODES][MAX_NODES];
int i,j;

void addEdge(int source, int destination) {
    if (source >= 0 && source < MAX_NODES && destination >= 0 && destination < MAX_NODES) {
        graph[source][destination] = 1;
        graph[destination][source] = 1;
    } else {
        printf("Invalid node indices.\n");
    }
}

void removeEdge(int source, int destination) {
    if (source >= 0 && source < MAX_NODES && destination >= 0 && destination < MAX_NODES) {
        graph[source][destination] = 0;
        graph[destination][source] = 0;
    } else {
        printf("Invalid node indices.\n");
    }
}

void printGraph() {
    printf("Graph Matrix:\n");
    for (i = 0; i < MAX_NODES;i++) {
        for (j = 0; j < MAX_NODES;j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void main() {
	int ch,src,des;
	for (i = 0; i < MAX_NODES; i++) 
	{
       for (j = 0; j < MAX_NODES; j++) 
	   {
           graph[i][j] = 0;
       }
   }
	while(ch!=4)
	{
		printf("\n\t\tMENU\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the source node: ");
				scanf("%d",&src);
				printf("\nEnter the destination node: ");
				scanf("%d",&des);
				addEdge(src,des);
				break;
			case 2:
				printf("\nEnter the source node: ");
				scanf("%d",&src);
				printf("\nEnter the destination node: ");
				scanf("%d",&des);
				removeEdge(src,des);
				break;
			case 3:
				printGraph();
				break;
			case 4:
				exit(0);
			default:
				printf("\nEnter valid input");
		}
	}
}
