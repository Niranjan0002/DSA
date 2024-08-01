struct arrADT
{
int size;
int a[100];
};

void create(struct arrADT *A,int size,int array[])
{
	A->size=size;
	for(int i=0;i<size;i++)
	{
		A->a[i]=array[i];
	}
}

void printArray(struct arrADT *A)
{
	for(int i=0;i<(A->size);i++)
	{
		printf("%d ",A->a[i]);
	}
	printf("\n");
}

void deleteAt(struct arrADT *A,int pos)
{
	for(int i=pos-1;i<((A->size)-1);i++)
	{
		A->a[i]=A->a[i+1];
	}
	A->size=(A->size)-1;
}

void deleteAtFront(struct arrADT *A)
{
	int pos=1;
	for(int i=pos-1;i<((A->size)-1);i++)
	{
		A->a[i]=A->a[i+1];
	}
	A->size=(A->size)-1;
}

void deleteAtMiddle(struct arrADT *A)
{
	int pos=(A->size)/2;
	pos+=1;
	for(int i=pos-1;i<((A->size)-1);i++)
	{
		A->a[i]=A->a[i+1];
	}
	A->size=(A->size)-1;
}

void deleteAtEnd(struct arrADT *A)
{
	int pos=(A->size);
	for(int i=pos-1;i<((A->size)-1);i++)
	{
		A->a[i]=A->a[i+1];
	}
	A->size=(A->size)-1;
}

void insertAtEvery(struct arrADT *A,int data)
{
	for(int i=(A->size)-1;i>=0;i--)
	{
		A->a[(i*2)+1]=A->a[i];
		A->a[i*2]=data;
	}
	A->size=(A->size)*2;
}

void insertAtFront(struct arrADT *A,int data)
{
	for(int i=(A->size)-1;i>=0;i--)
	{
		A->a[i+1]=A->a[i];
	}
	A->a[0]=data;
	A->size=(A->size)+1;
}

void insertAtMiddle(struct arrADT *A,int data)
{
	for(int i=(A->size)-1;i>=((A->size)/2);i--)
	{
		A->a[i+1]=A->a[i];
	}
	A->a[((A->size)/2)]=data;
	A->size=(A->size)+1;
}

void insertAtEnd(struct arrADT *A,int data)
{
	A->a[(A->size)]=data;
	A->size=(A->size)+1;
}

int search(struct arrADT *A,int key)
{
	int c=0,pos=-1;
	for(int i=0;i<(A->size);i++)
	{
		if(c==2)
		break;
		if(A->a[i]==key)
		{
			pos=i+1;
			++c;
		}
	}
	return pos;
}

int findPeek(struct arrADT *A,int p[])
{
	int c=0,l=A->size;
	if(A->a[0]>A->a[1])
	{
		p[c++]=A->a[0];
	}
	for(int i=1;i<l-1;i++)
	{
		if(A->a[i]>A->a[i-1] && A->a[i]>A->a[i+1])
		{
			p[c++]=A->a[i];
		}
	}
	if(A->a[l-1]>A->a[l-2])
	{
		p[c++]=A->a[l-1];
	}
	return c;
}