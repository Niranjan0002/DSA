struct tree 
{
  int data;
  struct tree *left, *right;
};

struct tree* insert (struct tree *t, int x)
{
  if (t==NULL)
  {
    t = (struct tree*)malloc(sizeof(struct tree));
    t->data = x;
    t->left = t->right = NULL;
  }
  if (x<t->data)
  t->left = insert(t->left,x);
  if (x>t->data)
  t->right = insert(t->right,x);
  return t;
}

void inorder (struct tree* t)
{
  if (t->left!=NULL)
  inorder (t->left);
  printf ("%d", t->data);
  if (t->right!=NULL)
  inorder (t->right);
}

void array (struct tree* t, int a[], int c)
{
  if (t->left!=NULL)
  array (t->left, a, c++);
  a[c++] = t->data;
  if (t->right!=NULL)
  array (t->right, a, c++);
}

void print (int a[], int c)
{
  for (int i=0;i<c;i++)
    printf ("%d ", a[i]);
  printf ("\n");
}

int check (int a1[], int a2[], int len)
{
  int i,flag=0;
  for (i=0;i<len;i++)
  {
    if (a1[i]==a2[i])
    flag++;
  }
  if (flag==len)
  return 1;
  else
  return 0;
}

int count_nodes (struct tree* t, int start, int end, int c)
{
  if (t->data>=start && t->data<=end)
    c++;  
  else if (t==NULL)
    return c;
  else
  {
    if (t->left!=NULL)
    count_nodes (t->left,start,end,c);
    if (t->right!=NULL)
    count_nodes (t->right,start,end,c);
  }
}

int sum (struct tree* t, int k, int a[])
{
  int sum=0;
  array (t,a,0);
  for (int i=0;i<k;i++)
    sum+=a[i];
  return sum;
}