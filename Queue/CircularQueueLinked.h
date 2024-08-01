struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if((r==NULL)&&(f==NULL))
    {
      f=r=temp;
      r->next=f;
    }
    else
    {
      r->next=temp;
      r=temp;
      temp->next=f;
    }
}

void dequeue()
{
    struct node *temp;
    temp=f;
    if((f==NULL)&&(r==NULL))
        printf("\nQueue is Empty");
    
    else if(f==r)
    {
      f=r=NULL;
      free(temp);
    }
    else
    {
      f=f->next;
      r->next=f;
      free(temp);
    }
}

void display ()
{				
    struct node *temp;
    temp=f;
    if((f==NULL)&&(r==NULL))
      printf("\nQueue is Empty");
    else
    {
      do
	  {
	    printf(" %d", temp->data);
	    temp=temp->next;
	  }
      while(temp!=f);
    }
}
