struct queue{
	int arr[100];
	int size;
	int front, rear;
};

void createQueue(struct queue* q, int size){
	q->size = size;
	q->front = q->rear = -1;
}

int isQueueFull(struct queue* q){
	if(q->rear + 1 >= q->size) return 1;
	else return 0;
}

int isQueueEmpty(struct queue* q){
	if(q->rear == -1 && q->front == -1) return 1;
	else if(q->front > q->rear){
		q->front = q->rear = -1;
		return 1;	
	}
	else return 0;
}

void enqueue(struct queue* q, int data){
	if(isQueueFull(q)){
		printf("\nQueue is full");
	}
	else{
		if(q->rear == -1){
			q->front++;
		}
		q->rear++;
		q->arr[q->rear] = data;
	}
}

int dequeue(struct queue* q){
	if(isQueueEmpty(q)){
		printf("\nQueue is empty");
		return -1;
	}
	else{
		int data = q->arr[q->front];
		q->front++;
		return data;
	}
}
