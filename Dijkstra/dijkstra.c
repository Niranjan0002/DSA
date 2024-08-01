#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

void main()
{
	int choice=1;
	int v,e;
	char c;
	char first,second;
	printf("Vertices = ");
	scanf("%d",&v);
	printf("Edges = ");
	scanf("%d",&e);
	printf("Edge pairs:\n");
	struct pair pairs[e];
	for(int i=0;i<e;i++)
	{
		printf("First, Second Point and distance= ");
		while ((c = getchar()) != '\n' && c != EOF) {}
		scanf("%c %c %d",&first,&second,&pairs[i].weight);
		pairs[i].first=(int)first-64;
		pairs[i].second=(int)second-64;
	}
	struct graph *G=(struct graph*)malloc(sizeof(struct graph));
	create(G, v, e, pairs);
	display(G);
	char x;
	printf("Staring point = ");
	while ((c = getchar()) != '\n' && c != EOF) {}
	scanf("%c",&x);
	printf("\n");
	dijkstra(G,(int)x-64);
	printf("\n");
	printf("Destination = ");
	while ((c = getchar()) != '\n' && c != EOF) {}
	scanf("%c",&x);
	path(G,(int)x-64);
	printf("\n");
}
