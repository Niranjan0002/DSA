#include<stdio.h>
#include<stdlib.h>
#include "tree.h"
int compare(struct tree *t1,struct tree *t2)
{
	struct node *h1,*h2;
    h1=(struct node *)malloc(sizeof(struct node));
	h1->next=NULL;
    h2=(struct node *)malloc(sizeof(struct node));
	h2->next=NULL;
	inorder1(t1,h1);
	inorder1(t2,h2);
	struct node *ptr1,*ptr2;
	ptr1=h1->next;
	ptr2=h2->next;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->data!=ptr2->data)
			return 0;
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
    if(ptr1!=NULL || ptr2!=NULL)
		return 0;
	return 1;
}
void main()
{
	struct tree *t1=NULL;
	struct tree *t2=NULL;
	int choice =1,data;
	while(choice)
	{
		printf("\n\n1.Insert t1\n2.Insert t2\n3.Inorder\n4.Preorder\n5.Postorder\n6.Delete t1\n7.Delete t2\n8.Compare\n0.Exit\nChoice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("Data = ");
				scanf("%d",&data);
				t1=insert(t1,data);
				break;
			}
			case 2:
			{
				printf("Data = ");
				scanf("%d",&data);
				t2=insert(t2,data);
				break;
			}
			case 3:
			{
				printf("Inorder t1:");
				inorder(t1);
				printf("\nInorder t2:");
				inorder(t2);
				break;
			}
			case 4:
			{
				printf("Preorder t1:");
				preorder(t1);
				printf("\nPreorder t2:");
				preorder(t2);
				break;
			}
			case 5:
			{
				printf("Postorder t1:");
				postorder(t1);
				printf("\nPostorder t2:");
				postorder(t2);
				break;
			}
			case 6:
			{
				printf("Data to be deleted = ");
				scanf("%d",&data);
				t1=delete(t1,data);
				break;
			}
			case 7:
			{
				printf("Data to be deleted = ");
				scanf("%d",&data);
				t2=delete(t2,data);
				break;
			}
			case 8:
			{
				if(compare(t1,t2))
					printf("Same tree");
				else
					printf("Different tree");
				break;
			}
			default:printf("Invalid Choice");
		}
	}
}