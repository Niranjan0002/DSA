struct emp
{
	char jid[100];
	int time;
};

struct queue
{
	struct emp e;
	struct queue *next;
};

int isEmpty(struct queue* ptr[])
{
	if(ptr[0]->next == NULL && ptr[1]->next == NULL) return 1;
	else return 0;
}

void display(struct queue *q[])
{
	for(struct queue* i = q[0]->next ; i!=NULL ; i = i->next){
		printf("%s ", i->e.jid);
	}
}

void enqueue(struct queue* ptr[], struct emp e)
{
    struct queue *temp = (struct queue*)malloc(sizeof(struct queue));
    strcpy(temp->e.jid, e.jid);
	temp->e.time = e.time;

    temp->next = NULL;

    if(ptr[0]->next == NULL){
        ptr[0]->next = temp;
	}
    else
        ptr[1]->next = temp;
    ptr[1] = temp;
}

struct emp* dequeue(struct queue* ptr[])
{
    struct queue *ptr1;
	struct emp *e = (struct emp *)malloc(sizeof(struct emp));
    if(ptr[0]->next != NULL){
        ptr1 = ptr[0]->next;
		strcpy(e->jid, ptr1->e.jid);
		e->time = ptr1->e.time;
        ptr[0]->next = ptr1->next;
        free(ptr1);    
        return e;
    }
    else{
        return NULL;
    }
      
}