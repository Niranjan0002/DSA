#include <stdio.h>
#include <stdlib.h>
#include "queueLLADT.h"
void main ()
{
  struct Queue * ptr[2];
  for (int i=0;i<2;i++)
  {
    ptr[i] = (struct Queue*)malloc(sizeof(struct Queue));
    ptr[i]->next = NULL;
  }


  
  enqueue (ptr,2);
  printf ("Front : %d ", ptr[0]->next->data);
  printf ("Rear : %d\n", ptr[1]->data);
  enqueue (ptr,4);
  printf ("Front : %d ", ptr[0]->next->data);
  printf ("Rear : %d\n", ptr[1]->data);
  enqueue (ptr,6);
  printf ("Front : %d ", ptr[0]->next->data);
  printf ("Rear : %d\n", ptr[1]->data);
  printf ("%d\n", dequeue (ptr));
  printf ("Front : %d ", ptr[0]->next->data);
  printf ("Rear : %d\n", ptr[1]->data);
  printf ("%d\n", dequeue (ptr));
  printf ("Front : %d ", ptr[0]->next->data);
  printf ("Rear : %d\n", ptr[1]->data);
  printf ("%d\n", dequeue (ptr));
  printf ("Front : %d ", ptr[0]->next->data);
  printf ("Rear : %d\n", ptr[1]->data);
  printf ("%d\n", dequeue (ptr));
  printf ("Front : %d ", ptr[0]->next->data);
  printf ("Rear : %d\n", ptr[1]->data);
}