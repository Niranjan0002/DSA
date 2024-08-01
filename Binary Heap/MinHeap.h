struct PQ
{
	int data[100];
	int size;
};

void create(struct PQ* P)
{
	P->size=0;
	P->data[0]=-100;
}

void insert(struct PQ* P,int x)
{
	int i;
	for(i=++P->size;P->data[i/2]>x;i/=2)
	{
		P->data[i]=P->data[i/2];
	}
	P->data[i]=x;
}

int deleteMin(struct PQ* P)
{
	if(P->size<1)
	{
		printf("Queue Empty");
		return -100;
	}
	int i,child;
	int min=P->data[1];
	int last=P->data[P->size--];
	for(i=1;(i*2)<=P->size;i=child)
	{
		child=i*2;
		if(P->data[child+1]<P->data[child])
		{
			child++;
		}
		if(last>P->data[child])
		{
			P->data[i]=P->data[child];
		}
		else
			break;
	}
	P->data[i]=last;
	return min;
}

void print(struct PQ* P)
{
	for (int i=1;i<=P->size;i++)
	printf("(%d) ",P->data[i]);
}
		
