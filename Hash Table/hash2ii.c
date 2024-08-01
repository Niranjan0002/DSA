//double hashing

#include <stdio.h>
#include <stdlib.h>
#include "hash2ii.h"

void main ()
{
  struct hashtable* H = (struct hashtable *)malloc(sizeof(struct hashtable));
  int choice=1,size,data;
  printf("Size = ");
  scanf("%d",&size);
  create(H,size);
  // printf("%d",H->size);
  while(choice)
  {
    printf("\n1.Insert\n2.Print\nChoice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Element = ");
        scanf("%d",&data);
        printf("%d",primeNo(H));
        insert(H,data);
        break;
        case 2:
        display(H);
        break;
    }
  }
}