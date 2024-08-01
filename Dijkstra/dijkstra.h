#include "graph.h"

void init(struct graph *G)
{
	for(int i=1;i<=G->v;i++)
	{
		G->t[i].k=0;
		G->t[i].d=999;
		G->t[i].p=-1;
		G->t[i].v=i;
	}
}

void printTable(struct graph *G)
{
	printf("\n\nV K D P");
	for(int i=1;i<=G->v;i++)
	{
		printf("\n%d %d %d %d",G->t[i].v,G->t[i].k,G->t[i].d,G->t[i].p);
	}
}

int check(struct graph *G)
{
	for(int i=1;i<=G->v;i++)
	{
		if(G->t[i].k==0)
			return 1;
	}
	return 0;
}

int minimum(struct graph *G)
{
	int min=999;
	int v=-1;
	for(int i=1;i<=G->v;i++)
	{
		if(G->t[i].d<min && G->t[i].k==0)
		{
			min=G->t[i].d;
			v=i;
		}
	}
	return v;
}

void dijkstra(struct graph *G, int s)
{
	init(G);
	int v;
	G->t[s].d=0;
	while(check(G))
	{
		printTable(G);
		v=minimum(G);
		G->t[v].k=1;
		for(int i=1;i<=G->v;i++)
		{
			if(G->adj[v][i]!=0 && G->t[i].k==0)
			{
				if(G->t[i].d>(G->t[v].d + G->adj[v][i]))
				{
					G->t[i].d=G->t[v].d + G->adj[v][i];
					G->t[i].p=v;
				}
			}
		}
	}
	printTable(G);
}

void path(struct graph *G,int v)
{
	if(G->t[v].p!=-1)
	{
		path(G,G->t[v].p);
		printf("->");
	}
	printf("%c",v+64);
}

