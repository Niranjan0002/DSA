#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

int precedence (char ch)
{
	switch (ch)
	{
		case '+':
		case '-':
		return 1;
		case '*':
		case '/':
		return 2;
		case '(':
		case ')':
		return 3;
		default:
		return 0;
	}
}

int isOperator (char ch)
{
	if (ch=='+' || ch=='-' || ch=='*' || ch=='/'|| ch=='('|| ch==')')
	    return 1;
	return 0;
}

void main ()
{
	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	char postfix[100];
    createStack(s, 100);
    int len=0,i=0,j=0,k; 
    char infix[100];
    printf ("Infix Expression : ");
    scanf ("%s", infix);
    while (infix[i]!='\0')
    {
      len++; i++;
    }
	for (i=0;i<len;i++)
	{
		if (isOperator(infix[i]))
		{
			if (isEmpty(s))
			    push (s,infix[i]);
			else 
			{
				if (infix[i]==')')
				{
					while (peek(s)!='(')
					{
						if (peek(s)!='(' && peek(s)!=')')
						postfix[j++] = peek(s);
						pop (s);
					} 
					pop(s);
				}
				else if (precedence(infix[i])>precedence(peek(s)) || peek(s)=='(')
				    push (s,infix[i]);
				else
				{
                    while (precedence(infix[i])<=precedence(peek(s)))
                    {
                        postfix [j++] = peek(s);
					    pop(s);
                    }
					push (s,infix[i]);
				}
			}
		}
		else
		    postfix[j++] = infix[i];
	}
	while (!isEmpty(s))
	{
		postfix[j++] = peek(s);
		pop (s);
	}
    printf("Postfix Expression : ");
	for (k=0;k<j;k++)
	    printf ("%c",postfix[k]);
    printf ("\n");
}
