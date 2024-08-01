struct hashtable
{
    int size;
    int table[100];
};

void create (struct hashtable *H, int size)
{
  H->size = size;
  for (int i=0;i< H->size; i++)
  {
    H->table[i]=-1;
  }
}

void insert (struct hashtable *H, int x)
{
  int pos,flag=1;
  for(int i=0;i<H->size;i++)
  {
    pos=(x+(i*i))%(H->size);
    if(H->table[pos]==-1)
    {
        H->table[pos]=x;
        flag=0;
        break;
    }
  }
  if(flag)
  {
    printf("Hash Table is full.\n");
  }
}


void display (struct hashtable *H)
{
  printf("Hash Table Elements : ");
  for(int i=0;i<H->size;i++)
  {
    if(H->table[i]!=-1)
    {
        printf("%d-%d ",i,H->table[i]);
    }
  }
  printf("\n");
}