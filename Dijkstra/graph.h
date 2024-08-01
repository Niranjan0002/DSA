#include "stack.h"
#include "queue.h"

struct table 
{
	int v,k,d,p;
};
struct graph
{
	int adj[100][100];
	int v;
	struct table t[100];
};

struct pair
{
	int first;
	int second;
	int weight;
};

void create(struct graph *G, int v, int e, struct pair pairs[])
{
	G->v=v;
	for(int i=0;i<e;i++)
	{
		G->adj[pairs[i].first][pairs[i].second]=pairs[i].weight;
	}
}

void display(struct graph *G)
{
	printf("  ");
	for(int i=1;i<=G->v;i++)
		printf("%c ",(char)(i+64));
	printf("\n");
	for(int i=1;i<=G->v;i++)
	{
		printf("%c ",(char)(i+64));
		for(int j=1;j<=G->v;j++)
		{
			printf("%d ",G->adj[i][j]);
		}
		printf("\n");
	}
}

void visit(int vis[], int x)
{
	vis[x]=1;
	printf("%d ",x);
}

void BFS(struct graph *G, int x)
{
	struct queue *Q=(struct queue*)malloc(sizeof(struct queue));
	createQueue(Q,G->v);
	int vis[G->v+1];
	visit(vis,x);
	enqueue(Q,x);
	while(!isQueueEmpty(Q))
	{
		int z=dequeue(Q);
		for(int i=1;i<=G->v;i++)
		{
			if(G->adj[z][i] == 1 && vis[i]!=1)
			{
				visit(vis,i);
				enqueue(Q,i);
			}
		}
	}
}

void DFS(struct graph *G, int x)
{
	struct stack *S=(struct stack*)malloc(sizeof(struct stack));
	createStack(S,G->v);
	int visit[G->v+1];
	visit[x]=1;
	printf("%d ",x);
	push(S,x);
	while(!isStackEmpty(S))
	{
		for(int i=1;i<=G->v;i++)
		{
			int t=peek(S);
			if(G->adj[t][i] == 1 && visit[i]!=1)
			{
				visit[i]=1;
				push(S,i);
				printf("%d ",i);
			}
		}
		pop(S);
	}
}



