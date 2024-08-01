#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void main()
{
	int choice=1;
	int v,e;
	char first,second;
	char source,destination;
	printf("Vertices = ");
	scanf("%d",&v);
	printf("Edges = ");
	scanf("%d",&e);
	printf("Directed (y|n) = ");
	while ((getchar()) != '\n');
	char c=getchar();
	printf("Edge pairs:\n");
	struct pair pairs[e];
	for(int i=0;i<e;i++)
	{
		printf("First and Second Point = ");
		while ((getchar()) != '\n');
		scanf("%c %c",&first,&second);
		pairs[i].first=(int)first-64;
		pairs[i].second=(int)second-64;
	}
	struct graph *G=(struct graph*)malloc(sizeof(struct graph));
	create(G, v, e, pairs, c);
	while(choice)
	{
		printf("\n\n1.Display\n2.BFS AND DFS\n3.Find Path\n4.Connected Components\n5.Exit\nChoice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				display(G);
				break;
			case 2:
			{
				printf("Staring point = ");
				while ((getchar()) != '\n');
				char x=getchar();
				printf("BFS = ");
				BFS(G,((int)x-64));
				printf("\nDFS = ");
				DFS(G,((int)x-64));
				break;
			}
			case 3:
			{
				printf("Source = ");
				while ((getchar()) != '\n');
				char source=getchar();
				printf("Destination = ");
				while ((getchar()) != '\n');
				char destination=getchar();
				if(path(G, ((int)source-64), ((int)destination-64)))
					printf("Path exists");
				else
					printf("Path not exists");
				break;
			}
			case 4:
			{
				connectedComponents(G);
				break;
			}
			case 5:
			choice=0;
			break;
			default:
			printf("Invalid Choice");
		}
	}
}