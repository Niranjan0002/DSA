//separate chaining

struct node
{
  int data;
  struct node* next;
};

struct hashtable
{
  int s;
  struct node* list[100];
};

void create (struct hashtable *H, int size)
{
  H->s = size;
  for (int i=0;i< H->s; i++)
  {
    H->list[i] = (struct node*)malloc(sizeof(struct node));
    H->list[i]->next = NULL;
  }
}

void insert (struct hashtable *H, int x)
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->next = NULL;
  temp->data = x;
  int h = x % H->s;
  struct node*  ptr = H->list[h];
  while (ptr->next!=NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = temp;
}

void print (struct hashtable *H)
{
  for (int i=0;i<H->s;i++)
  {
    printf ("\n%d - ", i);
    struct node* header = H->list[i];
    struct node* ptr = header->next;
    while (ptr!=NULL)
      {
        if (ptr==header->next)
          printf (" %d ", ptr->data);
        else
          printf (" -> %d", ptr->data);
        ptr = ptr->next;
      }
  }
  printf ("\n");
}

void search (struct hashtable *H, int x)
{
  int h = x % H->s;
  struct node* ptr = H->list[h];
  while (ptr->next!=NULL)
    {
      ptr = ptr->next;
      if (ptr->data==x)
      {
        printf ("\nElement %d found.\n", x);
        return;
      }
    }
  printf ("\nElement %d not found.\n", x);
}