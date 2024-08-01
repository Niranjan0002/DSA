#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"empqueueAdt.h"

int waitingTime(struct queue* ptr[])
{
	if(isEmpty(ptr)) return 0;
	int sum = 0;
	struct queue *temp = ptr[0]->next ;
	while(temp != NULL){
		sum += temp->e.time;
		temp = temp->next;
	}
	return sum;
}

void allocateJob(struct queue* ptr1[], struct queue* ptr2[], struct emp job)
{
	if(waitingTime(ptr1) <= waitingTime(ptr2)) enqueue(ptr1, job);
	else enqueue(ptr2, job);
} 

int main()
{
	int choice = 1;
	struct queue *ptr1[2];
    for(int i = 0 ; i < 2 ; i++)
        ptr1[i] = (struct queue*)malloc(sizeof(struct queue));
    ptr1[0]->next = NULL;
    ptr1[1]->next = NULL;
	struct queue *ptr2[2];
    for(int i = 0 ; i < 2 ; i++)
        ptr2[i] = (struct queue*)malloc(sizeof(struct queue));
    ptr2[0]->next = NULL;
    ptr2[1]->next = NULL;
	while(choice)
	{
		printf("\n\n1. Enqueue\n2. Dequeue queue 1\n3. Dequeue queue 2\n0. Exit\nEnter choice: ");
		scanf("%d", &choice); 
		switch(choice)
		{
			case 1: 
			{
				struct emp job;
				printf("Enter job ID: ");
				scanf("%s", &job.jid);
				printf("Enter time: ");
				scanf("%d", &job.time);
				allocateJob(ptr1, ptr2, job);
				printf("QUEUE1 > "); 
				display(ptr1);
				printf("\nQUEUE2 > "); 
				display(ptr2);
				break;
			}
			case 2: 
			{
				struct emp *deq = dequeue(ptr1);
				if(deq != NULL){
					printf("%s is removed", deq->jid);
				}
				printf("\nQUEUE1 > "); 
				display(ptr1);
				printf("\nQUEUE2 > "); 
				display(ptr2);
				break;
			}
			case 3: 
			{
				struct emp *deq = dequeue(ptr2);
				if(deq != NULL){
					printf("%s is removed", deq->jid);
				}
				printf("\nQUEUE1 > "); 
				display(ptr1);
				printf("\nQUEUE2 > "); 
				display(ptr2);
				break;
			}
		}
	}
}
