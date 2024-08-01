struct cq
{
  int data[100];
  int f,r,size;
};

void createQ (struct cq *q, int limit)
{
  q->size = limit;
  q->f = -1; q->r = -1;
}

void display(struct cq *q)
{
  if (q->f==-1 && q->r==-1)
    printf("Queue is empty.\n");
  else
  { 
    printf("QUEUE : ");
    for (int i=q->f;i<=q->r;i++)
    {
      printf("%d ",q->data[i]);
    }
    printf ("\n");
  }
}

void enqueue (struct cq *q, int x)
{
  if (q->f==-1 && q->r==-1)
  {
    q->f = 0; q->r = 0;
    q->data[q->f] = x;
  }
  else if ((q->r + 1)%q->size == q->f)
    printf ("\nQueue is full.\n");
  else
  {
    q->r = (q->r + 1)%q->size;
    q->data[q->r] = x;
  }
}

int dequeue (struct cq *q)
{
  if (q->f==-1 && q->r==-1)
    return -1;
  else if (q->f==q->r)
  {
    int d = q->data[q->f];
    q->f = -1; q->r = -1;
    return d;
  }
  else
  {
    int d = q->data[q->f];
    q->f = (q->f + 1)%q->size;
    return d;
  }
}