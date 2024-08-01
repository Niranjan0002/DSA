#include<stdio.h>
#include<stdlib.h>
#include"queueAdt.h"

int main(){
	int choice = 1;
	printf("\nEnter size of queue: ");
	int size;
	scanf("%d", &size);
	struct queue *q = (struct queue*) malloc(sizeof(struct queue));
	create(q, size);
	while(choice){
		
		printf("\n1. Enqueue\n2. Dequeue\n0. Exit\nEnter choice: ");
		scanf("%d", &choice); 
		switch(choice){
			case 1: {
				int data;
				printf("\nEnter data: ");
				scanf("%d", &data);
				enqueue(q, data);
				break;
			}
			case 2: {
				int deq = dequeue(q);
				if(deq != -1){
					printf("\n%d is removed", deq);
				}
				break;
			}
			case 3: break;
		}
	}
}
