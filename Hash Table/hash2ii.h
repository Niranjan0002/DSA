#include <stdio.h>

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

int primeNo (struct hashtable *H)
{
    int c=0;
    for(int i=H->size-1;i>0;i--)
    {
        c=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                ++c;
            }
        }
        if(c==2)
        {
            return i;
        }
    }
}

void insert (struct hashtable *H, int x)
{
  int pos,flag=1,hash2,prime;
  prime=primeNo(H);
  for(int i=0;i<H->size;i++)
  {
    hash2=prime-(x%prime);
    pos=((x%H->size)+(i*hash2))%(H->size);
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