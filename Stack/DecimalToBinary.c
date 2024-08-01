#include<stdio.h>
#include<stdlib.h>
#include"DecimalToBinary.h"

void DecimalToBinary(int num)
{
    struct stack *top = (struct stack *) malloc(sizeof(struct stack));
	createStack(top, 100);
    int rem;
    while(num!=0)
    {
        rem = num%2;
        push(top, rem);
        num/=2;
    }
    while(peek(top)!=-1)
        printf("%d", pop(top));
    printf("\n");
}

void main()
{
    int num;
    printf("Enter an integer : ");
    scanf("%d",&num);
    printf("Binary Equivalent is : ");
    DecimalToBinary(num);
}

