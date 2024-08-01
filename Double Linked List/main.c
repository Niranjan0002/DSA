#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedListADT.h"

void main ()
{
  struct node* header;
  header = (struct node*)malloc(sizeof(struct node));
  header->left = NULL;
  header->right = NULL;
  int choice;
  while(choice + 1)
	{
		printf("\n-1: EXIT\n 0: DISPLAY ITEMS\n 1: INSERT AT FRONT\n 2: INSERT AT END\n 3: INSERT AT MIDDLE\n 4: DELETE ITEM");
		printf("\n 5: SEARCH ITEM\n 6: CHECK DUPLICATES\n 7: SEPARATE EVEN AND ODD\n 8: ADD 10 DIGIT NO.\n 9: CHECK PALINDROME\nChoice : ");
		scanf("%d", &choice);
		switch (choice)
		{
			case -1: break;
			case 0:
			{
				displayItems(header);
        		printf("\n");
				break;
			}
			case 1:
			{
				printf("\nENTER NEW ELEMENT: ");
				int data;
				scanf("%d", &data);
				insertFront(header,data);
				displayItems(header);
        		printf("\n");	
				break;			
			}
			case 2:
			{
				printf("\nENTER NEW ELEMENT: ");
				int data;
				scanf("%d", &data);
				insertEnd(header,data);
				displayItems(header);
        		printf("\n");	
				break;		
			}
      		case 3:
			{
				printf("\nENTER NEW ELEMENT AND TO INSERT AFTER: ");
				int data,key;
				scanf("%d", &data);
        		scanf("%d", &key);
				insertMiddle(header,key,data);
				displayItems(header);
        		printf("\n");	
				break;		
			}
      		case 4:
			{
				printf("\nENTER ELEMENT: ");
				int data;
				scanf("%d", &data);
				deleteItem(header,data);
        		printf("ELEMENT DELETED\n");
				displayItems(header);
        		printf("\n");
				break;		
			}
      		case 5:
			{
				int search,c;
        		printf("\nEnter element to search: ");
        		scanf("%d", &search);
        		c=searchItem(header,search);
        		printf("\nThe no. of occurences of %d in the list is %d.\n",search, c);
				break;		
			}
      		case 6:
			{
        		if(!duplicates(header))
          			printf("\nNo duplicates present.");
        		else
          			printf("\nDuplicates present.");
        		printf("\n");
				break;		
			}
      		case 7:
			{
        		struct node *even_head = (struct node *)malloc(sizeof(struct node));
        		even_head->left = NULL;
        		even_head->right = NULL;
        		struct node *odd_head = (struct node *)malloc(sizeof(struct node));
        		odd_head->left = NULL;
        		odd_head->right = NULL;
				evenOdd(header,even_head,odd_head);
        		printf("\nEven List: ");
        		displayItems(even_head);
        		printf("\nOdd List: ");
        		displayItems(odd_head);
        		printf("\n");
				break;		
			}
			case 8:
			{
				struct node *n1=(struct node *)malloc(sizeof(struct node));
				n1->left=NULL;
				n1->right=NULL;
				struct node *n2=(struct node *)malloc(sizeof(struct node));
				n2->left=NULL;
				n2->right=NULL;
				struct node *sum=(struct node *)malloc(sizeof(struct node));
				sum->left=NULL;
				sum->right=NULL;
				char num1[11],num2[11];
				printf("Number 1 : ");
				scanf("%10s", num1);
				printf("Number 2 : ");
				scanf("%10s", num2);
				for(int i=0;i<10;i++)
				{
					insertEnd(n1,(num1[i]-'0'));
				}
				for(int i=0;i<10;i++)
				{
					insertEnd(n2,(num2[i]-'0'));
				}
				printf("Number 1 : ");
				displayItems(n1);
        		printf("\n");
				printf("Number 2 : ");
				displayItems(n2);
        		printf("\n");
				sum=add10Digit(n1,n2);
				printf("Sum : ");
				displayItems(sum);
        		printf("\n");
				break;
			}
			case 9:
			{
				if(palindrome(header))
          			printf("\nPalindrome.");
        		else
          			printf("\nNot Palindrome.");
        		printf("\n");
				break;
			}
			default:
			{
				printf("\nINVALID CHOICE");
			}
		}
	}
}