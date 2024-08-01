#include<stdio.h>
#include<stdlib.h>
#include "tree.h"
void main()
{
	struct tree *t=NULL,*s;
	int choice =1,data,key;
	while(choice)
	{
		printf("\n\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Delete\n6.Search\n7.Level Order\n0.Exit\nChoice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("Data = ");
				scanf("%d",&data);
				t=insert(t,data);
				break;
			}
			case 2:
			{
				printf("Inorder t:");
				inorder(t);
				break;
			}
			case 3:
			{
				printf("Preorder t:");
				preorder(t);
				break;
			}
			case 4:
			{
				printf("Postorder t:");
				postorder(t);
				break;
			}
			case 5:
			{
				printf("Data to be deleted = ");
				scanf("%d",&data);
				t=delete(t,data);
				break;
			}
			case 6:
      		{
        		printf ("Enter element to search: ");
        		scanf ("%d", &key);
        		s = search (t,key);
        		if (s==NULL)
        			printf ("Element not found.");
        		else
        			printf ("Element %d found.", s->data);
        		break;
      		}
			case 7:
      		{
        		for (int i=0; i<=height (t); i++)
          		{
            		level(t,i);
            		printf("\n");
          		}
        		break;
      		}
			default:printf("Invalid Choice");
		}
	}
}
