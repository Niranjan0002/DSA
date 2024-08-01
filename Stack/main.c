#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main()
{
	int size;
	printf("Enter size: ");
	scanf("%d", &size);
	struct stack *top = (struct stack *) malloc(sizeof(struct stack));
	createStack(top, size);
	
	int choice = 1;
	while(choice)
	{
		printf("\n0: QUIT\n1: Push\n2: Pop\n3: Peek\nEnter choice:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 0: break;
			case 1: 
			{
				int data;
				printf("Enter data: ");
				scanf("%d", &data);
				push(top, data);
				break;
			}
			case 2: 
			{
				pop(top);
				break;	
			}
			case 3: 
			{
				int val = peek(top);
				if(val!= -1) 
					printf("Peek is %d\n", val);
				else 
					printf("Stack is Empty\n");
				break;	
			}
			default: printf("\nEnter valid Choice");		
		}
	}
}
