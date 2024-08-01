#include <stdio.h>
#include <stdlib.h>
#include "LinkedADT.h"

void main()
{

	struct node *head = (struct node*) malloc(sizeof(struct node));
	head->next = NULL;
	printf("ENTER FIRST ELEMENT: ");
	int value;
	scanf("%d", &value);
	create(head, value);

	int choice;
	while(choice + 1)
	{
		printf("\n-1: EXIT\n 0: DISPLAY\n 1: APPEND(INSERT AT END)\n 2: INSERT AT BEGINNING\n 3: INSERT AFTER DATA\n 4: DELETE AT FRONT");
		printf("\n 5: DELETE AT END\n 6: DELETE DATA\n 7: SEARCH DATA\n 8: REVERSE\n 9: MIDDLE ELEMENT\n 10: DETECT LOOP\nChoice : ");
		scanf("%d", &choice);
		switch (choice)
		{
			case -1: break;
			case 0:
			{
				display(head);
				break;
			}
			case 1:
			{
				printf("\nENTER NEW ELEMENT: ");
				int data;
				scanf("%d", &data);
				append(head, data);
				printf("New List : ");
				display(head);	
				break;			
			}
			case 2:
			{
				printf("\nENTER NEW ELEMENT: ");
				int data;
				scanf("%d", &data);
				insertAtFront(head, data);
				printf("New List : ");
				display(head);	
				break;		
			}
			case 3:
			{
				printf("\nENTER NEW ELEMENT: ");
				int data;
				scanf("%d", &data);
				
				printf("\nENTER KEY: ");
				int key;
				scanf("%d", &key);
				
				insertAfter(head, data, key);
				printf("New List : ");
				display(head);	
				break;		
			}
			case 4:
			{
				deleteAtFront(head);
				printf("New List : ");
				display(head);
				break;
			}
			case 5:
			{
				deleteAtEnd(head);
				printf("New List : ");
				display(head);
				break;
			}
			case 6:
			{
				printf("\nENTER ELEMENT TO DELETE: ");
				int data;
				scanf("%d", &data);
				deleteData(head, data);
				printf("New List : ");
				display(head);
				break;
				
			}
			case 7:
			{
				printf("\nENTER DATA TO SEARCH: ");
				int data;
				scanf("%d", &data);
				if(search(head, data)!=NULL)
				{
					printf("ELEMENT FOUND\n");
				}
				else
				{
					printf("ELEMENT NOT FOUND\n");
				}
				break;
				
			}
			case 8:
			{
				printf("\nLIST REVERSED ");
				reverse(head);
				printf("New List : ");
				display(head);
				break;
			}
			case 9:
			{
				printMiddle(head);
			}
			case 10:
			{
				if(detectLoop(head))
				{
					printf("\nLoop Present\n");
				}
				else
				{
					printf("\nNo Loop Present\n");
				}
				break;
			}
			case 11:
			{
				head->next->next->next->next=head->next;
				break;
			}
			default:
			{
				printf("\nINVALID CHOICE");
			}
			
		}
	}
}
