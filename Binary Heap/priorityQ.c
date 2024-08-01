#include <stdio.h>
#include <stdlib.h>
#include "priorityQ.h"

void main ()
{
	struct pq*p = (struct pq*)malloc(sizeof(struct pq));
	init (p);
	int d, ch=-1; char x;
	struct emp e;
	while (ch!=0)
	{
		printf ("\nMENU:\n1 - Insert\n2 - Delete maximum element\n3 - Print\n0 - Exit\nEnter your choice: ");
		scanf ("%d", &ch);
		scanf ("%c", &x);
		switch (ch)
		{
			case 1:
			{
				printf ("Enter element to insert: ");
				scanf ("%c", &e.id);
				scanf ("%c", &x);
				scanf ("%d", &e.salary);
				insert (p,e.id,e.salary);
				break;
			}
			case 2:
			{
				e = deletemax (p);
				printf ("\n(%c,%d) is deleted.\n", e.id,e.salary);
				break;
			}
			case 3:
			{
				print (p);
				break;
			}
			case 0:
			{
				printf ("Quitting ...\n");
				break;
			}
			default:
			printf ("\nInvalid choice. Enter again.\n");
		}
	}
}
