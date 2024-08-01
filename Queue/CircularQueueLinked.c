#include<stdio.h>
#include<stdlib.h>
#include"CircularQueueLinked.h"

int main()
{
	int choice=1;
	while(choice)
    {
		printf("\n1. Enqueue\n2. Dequeue\n0. Exit\nEnter choice: ");
		scanf("%d", &choice); 
		switch(choice)
        {
			case 1: 
            {
				int data;
				printf("\nEnter data: ");
				scanf("%d", &data);
				enqueue(data);
                printf("Queue after Enqueue : ");
                display();
                printf("\n");
				break;
			}
			case 2: 
            {
				dequeue();
                printf("Queue after Dequeue : ");
                display();
                printf("\n");
				break;
			}
			case 0: break;
		}
	}
}