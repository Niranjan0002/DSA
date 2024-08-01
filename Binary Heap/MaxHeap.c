#include<stdio.h>
#include<stdlib.h>
#include"MaxHeap.h"

void main()
{

	struct PQ* P=(struct PQ*)malloc(sizeof(struct PQ));
	int choice=1;
	int el;
	create(P);
	while(choice)
	{
		printf("\n\n1.Insert\n2.Delete Maximum\n3.Display\n4.Exit\nChoice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter the element: ");
			scanf("%d",&el);
			insert(P,el);
			break;
			case 2:
			el=deleteMin(P);
			if(el!=930)
			printf("Max Element = %d",el);
			break;
            case 3:
            printf("Elements : ");
            print(P);
			case 4:
			exit(0);
			break;
			default:
			printf("Invalid Choice");
		}
	}
}