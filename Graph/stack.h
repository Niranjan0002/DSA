struct stack{
	int arr[100];
	int size;
	int top;
};

void createStack(struct stack *s, int size){
	s->size = size;
	s->top = -1;
}

int isStackEmpty(struct stack *s){
	if(s->top == -1) return 1;
	else return 0;
}

int isStackFull(struct stack *s){
	if(s->top + 1 >= s->size) return 1;
	else return 0;
}

void push(struct stack *s, int data){
	if(isStackFull(s)){
		printf("\nStack is Full");
	}
	else{
		s->top += 1;
		s->arr[s->top] = data;	
	}
}

int pop(struct stack *s){
	if(isStackEmpty(s)){
		return -1;
	}
	else{	
		int val = s->arr[s->top];
		s->top -= 1;
		return val;
	}
}

int peek(struct stack *s){
	if(isStackEmpty(s)){
		return -1;
	}
	else{
		return s->arr[s->top];
	}
}
