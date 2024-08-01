#include <stdio.h>
#include <stdlib.h>
#include "CircularQ.h"
void main ()
{
  struct cq *q = (struct cq*)malloc(sizeof(struct cq));
  int choice;
  printf("ENTER SIZE OF QUEUE : ");
  int size;
	scanf("%d", &size);
	createQ (q,size);
  while(choice + 1)
	{
		printf("\n-1: EXIT\n0: DISPLAY ITEMS\n1: ENQUEUE\n2: DEQUEUE\nChoice : ");
		scanf("%d", &choice);
		switch (choice)
		{
			case -1: break;
			case 0:
			{
				display (q);
				break;
			}
			case 1:
			{
				printf("\nENTER NEW ELEMENT : ");
				int data;
				scanf("%d", &data);
				enqueue(q,data);
				display(q);	
				break;		
			}
      case 2:
			{
				printf("\n%d is dequeued.\n", dequeue (q));
        display(q);	
				break;		
			}
			default:
			{
				printf("\nINVALID CHOICE");
			}
		}
	}
}