//separate chaining

#include <stdio.h>
#include <stdlib.h>
#include "hash1.h"

void main ()
{
  struct hashtable* H = (struct hashtable *)malloc(sizeof(struct hashtable));
  create (H,10);
  insert(H,23);
  insert(H,45);
  insert(H,69);
  insert(H,87);
  insert(H,48);
  insert(H,67);
  insert(H,54);
  insert(H,66);
  insert(H,53);
  print (H);
  search (H,45);
  search (H,67);
  search (H,12);
}