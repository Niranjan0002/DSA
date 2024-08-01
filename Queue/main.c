#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"

int main()
{
    int choice = 1;
    struct queue *Q[2];
    for(int i = 0 ; i < 2 ; i++)
        Q[i] = (struct queue*)malloc(sizeof(struct queue));
    Q[0]->next = NULL;
    Q[1]->next = NULL;
    struct emp e;
    printf("Dequeued %s", dequeue(Q)->jid);
    display(Q);
    printf("\n");
    strcpy(e.jid, "J1");
    e.time = 2;
    enqueue (Q, e);
    display(Q);
    printf("\n");
    strcpy(e.jid, "J2");
    e.time = 13;
    enqueue(Q, e);
    display(Q);
    printf("\n");
    strcpy(e.jid, "J3");
    e.time = 5;
    enqueue(Q, e);
    display(Q);
    printf("\n");
    printf("Dequeued %s\n", dequeue(Q)->jid);
    display(Q);
    printf("\n");
    printf("Dequeued %s\n", dequeue(Q)->jid);
    display(Q);
    printf("\n");
}