#include <stdio.h>
#include<stdlib.h>
struct queue{
    long data[100];
    int f,r,size;
};
void create(struct queue *q,int n){
    q->size = n;
    q->f = -1;
    q->r = -1;
}
int isEmpty(struct queue *q){
    if(q->f == -1)
        return 1;
    else
        return 0;
}
int isFull(struct queue *q){
    if((q->r+1)%q->size == q->f)
        return 1;
    else
        return 0;
}
void enqueue(struct queue *q,long x){
    if(isEmpty(q)){
        q->f = 0;
        q->r = 0;
        q->data[q->r] = x;
    }
    else if(isFull(q)){
        return;
    }
    else{
        q->r = (q->r+1)%(q->size);
        q->data[q->r] = x;
    }
}
long dequeue(struct queue *q){
    if(isEmpty(q))
        return -9999;
    else if(q->f == q->r){
        int d = q->data[q->f];
        q->f = -1;
        q->r = -1;
        return d;
    }
    else{
        int d = q->data[q->f];
        q->f = (q->f + 1)%(q->size);
        return d;
    }
}
int change(int x){
    if(x == 1)
        return 0;
    else
        return 1;
}
int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	struct queue *q;
	
	while(t > 0){
	    q = (struct queue*)malloc(sizeof(struct queue));
	    int n;
	    scanf("%d",&n);
	    create(q,n);
	    int ele;
	    long demo;
	    for(int i = 0;i < n;i++){
	        scanf("%ld",&demo);
	        enqueue(q,demo);
	    }
	    ele = 0;
	    while(q->f != q->r){
	        ele = change(ele);
	        if(ele == 1){
    	        enqueue(q,dequeue(q));
    	        if(!isEmpty(q))
    	            dequeue(q);
	        }
	        else{
	            enqueue(q,dequeue(q));
	            enqueue(q,dequeue(q));
	            if(!isEmpty(q))
    	            dequeue(q);
	        }
	    }
	    printf("\n%d %ld",ele,dequeue(q));
	    t--;
	    free(q);
	   //printf("ji");
	}
	
	return 0;
}