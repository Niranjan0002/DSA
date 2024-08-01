#include <stdio.h>
#include <stdlib.h>
#include "Polynomial.h"

void main()
{
    struct node *p1=(struct node *)malloc(sizeof(struct node));
    struct node *p2=(struct node *)malloc(sizeof(struct node));
    struct node *sum=(struct node *)malloc(sizeof(struct node));
    p1->next=NULL;
    p2->next=NULL;
    sum->next=NULL;
    int choice;
	while(choice + 1)
	{
		printf("\n-1: EXIT\n 0: DISPLAY POLYNOMIALS\n 1: INSERT AT POLYNOMIAL 1\n 2: INSERT AT POLYNOMIAL 2\n 3: DISPLAY SUM\nChoice : ");
		scanf("%d", &choice);
		switch (choice)
		{
			case -1: break;
			case 0:
			{
				printf("Polynomial 1: ");
                display(p1);
                printf("Polynomial 2: ");
                display(p2);
				break;
			}
			case 1:
			{
				printf("\nENTER COEFFICIENT AND EXPONENT: \n");
				int coef,exp;
				scanf("%d",&coef);
                scanf("%d",&exp);
				insert(p1,coef,exp);
				break;			
			}
            case 2:
			{
				printf("\nENTER COEFFICIENT AND EXPONENT: \n");
				int coef,exp;
				scanf("%d",&coef);
                scanf("%d",&exp);
				insert(p2,coef,exp);
				break;			
			}
            case 3:
			{
				printf("\nPOLYNOMIALS ADDED\n");
				add(p1,p2,sum);
                printf("Sum: ");
                display(sum);
				break;			
			}
			default:
			{
				printf("\nINVALID CHOICE");
			}
			
		}
	}
}