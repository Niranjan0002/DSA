struct node
{
  int data;
  struct node* left;
  struct node* right;
};

void insertFront(struct node* header, int c)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=c;
  if(header->right==NULL)
  {
    temp->right=header->right;
    temp->left=header;
    header->right=temp;
  }
  else
  {
    struct node* ptr;
    ptr=header->right;
    temp->right=ptr;
    ptr->left=temp;
    header->right=temp;
    temp->left=header;
  }
}

void displayItems(struct node* header)
{
  struct node* ptr, *end;
  ptr=header->right;
  printf("\nForward: ");
  while(ptr!=NULL)
    {
      printf("%d ", ptr->data);
      end=ptr;
      ptr=ptr->right;
    }
  printf("Backward: ");
  while(end!=header)
    {
      printf("%d ", end->data);
      end=end->left;
    }
}

struct node* search(struct node* header, int key)
{
  struct node* ptr;
  ptr=header->right;
  while(ptr!=NULL)
    {
      if(ptr->data==key)
        return ptr;
      ptr=ptr->right;
    }
  return NULL;
}

void insertMiddle(struct node* header, int key, int data)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  struct node *ptr, *next;
  ptr=search(header,key);
  if(ptr==NULL)
    printf("\nNot found.");
  else
  {
    temp->data=data;
    next=ptr->right;
    ptr->right=temp;
    temp->left=ptr;
    temp->right=next;
    next->left=temp;
  }
}

void insertEnd(struct node* header, int data)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  struct node *ptr;
  ptr=header;
  while(ptr->right!=NULL)
      ptr=ptr->right;
  temp->data=data;
  ptr->right=temp;
  temp->left=ptr;
  temp->right=NULL;
}

void deleteItem(struct node* header, int data)
{
  struct node *prev, *next, *ptr;
  ptr=search(header,data);
  prev=ptr->left;
  next=ptr->right;
  prev->right=next;
  next->left=prev;
  free(ptr);
}

int searchItem(struct node* header, int c)
{
  int count=0;
  struct node* ptr=header->right;
  while(ptr!=NULL)
    {
      if(ptr->data==c)
        ++count;
      ptr=ptr->right;
    }
  return count;
}

int duplicates(struct node* header)
{
  int flag;
  struct node* ptr1=header->right, *ptr2;
  while(ptr1!=NULL)
    {
      ptr2=ptr1->right;
      while(ptr2!=NULL)
        {
          if(ptr1->data==ptr2->data)
            return 1;
          ptr2=ptr2->right;
        }
      ptr1=ptr1->right;
    }
  return 0;
}

void evenOdd(struct node* header,struct node* even_head,struct node* odd_head)
{
  struct node *ptr = header->right;
  while (ptr != NULL) 
  {
    if ((ptr->data) % 2 == 0)
      insertEnd(even_head, ptr->data);
    else
      insertEnd(odd_head, ptr->data);
    ptr = ptr->right;
  }
}

int palindrome(struct node* header)
{
  struct node* ptr=header->right;
  struct node* end;
  while(ptr!=NULL)
  {
    end=ptr;
    ptr=ptr->right;
  }
  if(header->right!=NULL)
  {
    ptr=header->right;
    while(ptr!=NULL && end!=header)
    {
      if(ptr->data!=end->data)
        return 0;
      ptr=ptr->right;
      end=end->left;
      if(ptr==end)
        break;
    }
  }
  return 1;
}

struct node* add10Digit(struct node* n1,struct node* n2)
{
  struct node* res=(struct node*)malloc(sizeof(struct node));
  struct node *p1,*p2,*end1,*end2;
  p1=n1->right;
  p2=n2->right;
  res->left=NULL;
  res->right=NULL;
  int sum,carry=0;
  while(p1!=NULL)
  {
    end1=p1;
    end2=p2;
    p1=p1->right;
    p2=p2->right;
  }
  p1=end1;
  p2=end2;
  while(p1!=n1)
  {
    sum=p1->data+p2->data+carry;
    if(sum>9)
    {
      carry=1;
      insertFront(res,sum%10);
    }
    else
    {
      carry=0;
      insertFront(res,sum);
    }
    p1=p1->left;
    p2=p2->left;
  }
  if(carry==1)
  {
    insertFront(res,1);
  }
  return res;
}