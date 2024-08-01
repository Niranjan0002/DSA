#include<stdio.h>
#include<stdlib.h>
#include"AVLtree.h"

void main()
{

	struct tree* t=NULL;
	int choice=100;
	char el;
	while(choice!=4)
	{
		printf("\n\n1.Insert\n2.Print\n3.Find Parent\n4.Exit\nChoice = ");
		scanf("%d",&choice);
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		switch(choice)
		{
			case 1:
			printf("Enter the element: ");
			el=getchar();
			t=insert(t,el);
			break;
			case 2:
			hierarchical(t,0);
			printf("\n\n");
			break;
			case 3:
			printf("Enter the element: ");
			el=getchar();
			struct tree *parent=findParent(t,el);
			if(parent!=NULL)
				printf("Parent = %c",parent->data);
			else
				printf("Element Not Found");
			break;
			case 4:
			exit(0);
			break;
		}
	}
}
