struct stack
{
	 int top;
	 char a[100];
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
void push(struct stack *top,char data)
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
char pop(struct stack *top)
{
	char data;
	if(isEmpty(top))
		return -1;
	else
	{
		data=top->a[top->top];
		--top->top;
	}
	return data;
}
char peek(struct stack *top)
{
	if(isEmpty(top))
		return ' ';
	else
		return top->a[top->top];
}