struct stack
{
	 int top;
	 int a[100];
	 int size;
};
void createStack(struct stack *top,int size)
{
	top->size=size;
	top->top=-1;
}
int isFull(struct stack *top)
{
	if(top->top<(top->size-1))
		return 0;
	return 1;
}
void push(struct stack *top,int data)
{
	if(isFull(top))
		printf("Stack Full\n");
	else
		top->a[++top->top]=data;
}
int isEmpty(struct stack *top)
{
	if(top->top==-1)
		return 1;
	return 0;
}
void pop(struct stack *top)
{
	if(isEmpty(top))
		printf("Stack empty\n");
	else
	{
		--top->top;
		printf("Element Popped\n");
	}
}
int peek(struct stack *top)
{
	if(isEmpty(top))
		return -1;
	else
		return top->a[top->top];
}