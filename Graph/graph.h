#include "stack.h"
#include "queue.h"

struct graph
{
	int adj[100][100];
	int v;
};

struct pair
{
	int first;
	int second;
};

void create(struct graph *G, int v, int e, struct pair pairs[], char c)
{
	G->v=v;
	for(int i=0;i<e;i++)
	{
		if(c=='n' || c=='N')
		{
			G->adj[pairs[i].first][pairs[i].second]=1;
			G->adj[pairs[i].second][pairs[i].first]=1;
		}
		else if(c=='y' || c=='Y')
		{
			G->adj[pairs[i].first][pairs[i].second]=1;
		}
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
	printf("%c ",(char)(x+64));
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
	int vis[G->v+1];
	visit(vis,x);
	push(S,x);
	while(!isStackEmpty(S))
	{
		for(int i=1;i<=G->v;i++)
		{
			int t=peek(S);
			if(G->adj[t][i] == 1 && vis[i]!=1)
			{
				visit(vis,i);
				push(S,i);
			}
		}
		pop(S);
	}
}

int path(struct graph *G, int source, int destination)
{
	struct stack *S=(struct stack*)malloc(sizeof(struct stack));
	createStack(S,G->v);
	if(source==destination)
		return 1;
	int vis[G->v+1];
	vis[source]=1;
	push(S,source);
	while(!isStackEmpty(S))
	{
		for(int i=1;i<=G->v;i++)
		{
			int t=peek(S);
			if(G->adj[t][i] == 1 && vis[i]!=1)
			{
				if(destination==i)
					return 1;
				vis[i]=1;
				push(S,i);
			}
		}
		pop(S);
	}
	return 0;
}

void DFS1(struct graph *G, int x, int vis[])
{
	struct stack *S=(struct stack*)malloc(sizeof(struct stack));
	createStack(S,G->v);
	visit(vis,x);
	push(S,x);
	while(!isStackEmpty(S))
	{
		for(int i=1;i<=G->v;i++)
		{
			int t=peek(S);
			if(G->adj[t][i] == 1 && vis[i]!=1)
			{
				visit(vis,i);
				push(S,i);
			}
		}
		pop(S);
	}
}

void connectedComponents(struct graph* G) 
{
    int visited[G->v+1];
    printf("Connected Components:\n");
    for(int i=1;i<=G->v;i++) 
	{
        if (visited[i]!=1) 
		{
            DFS1(G, i, visited);
            printf("\n");
        }
    }
}