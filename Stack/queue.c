#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void  main()
{
	struct stack *s1=(struct stack *)malloc(sizeof(struct stack));
	struct stack *s2=(struct stack *)malloc(sizeof(struct stack));
	int size,choice,data;
	printf("Enter size : ");
	scanf("%d",&size);
	create(s1,size);
	create(s2,size);
	while(choice+1)
	{
		printf("\n-1: EXIT\n1: ENQUEUE\n2: DEQUEUE\nChoice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case -1:
			break;
			case 1:
			printf("Enter element : ");
			scanf("%d",&data);
			enqueue(s1,s2, data);
			break;
			case 2:
			if(!queueIsEmpty(s1, s2))
			printf("Element Removed = %d\n",dequeue(s1, s2));
			else printf("QUEUE IS EMPTY");
			break;
			default:
			printf("Invalid choice\n");
		}
	}
}
