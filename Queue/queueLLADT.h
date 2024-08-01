struct Queue 
{
  int data;
  struct Queue*next;
};

void enqueue (struct Queue *ptr[], int data)
{
  struct Queue *temp = (struct Queue *)malloc(sizeof(struct Queue));
  temp->data = data;
  temp->next = NULL;
  if (ptr[0]->next==NULL)
  {
    ptr[0]->next = temp;
    ptr[1] = temp;
  }  
  else
  {
    ptr[1]->next = temp;
    ptr[1] = temp;
  }
}

int dequeue (struct Queue *ptr[])
{
  if (ptr[0]->next==NULL)
  {
    ptr[0]->data = ptr[1]->data = -1;
    ptr[0]->next = ptr[1]->next = NULL;
    return -1;
  }  
  else
  {
    struct Queue *temp = ptr[0]->next;
    int d = temp->data;
    ptr[0]->next = temp->next;
    free (temp);
    return d;
  }
}