#include<stdio.h>
#include<stdlib.h>
#include"arrADT.h"
void main()
{
	struct arrADT *A;
	A=(struct arrADT *)malloc(sizeof(struct arrADT));
	int size;
	printf("Enter the size of the array : ");
	scanf("%d",&size);
	int a[size],p[size];
	printf("Enter %d array elements : \n",size);
	for(int i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	create(A,size,a);
	printArray(A);
	printf("Enter the position of element to be deleted : ");
	int pos;
	scanf("%d",&pos);
	deleteAt(A,pos);
	printArray(A);
	printf("Enter the data to be inserted : ");
	int data;
	scanf("%d",&data);
	printf("Inserting At Front :\n");
	insertAtFront(A,data);
	printArray(A);
	printf("Inserting At Middle :\n");
	insertAtMiddle(A,data);
	printArray(A);
	printf("Inserting At End :\n");
	insertAtEnd(A,data);
	printArray(A);
	printf("Deleting At Front :\n");
	deleteAtFront(A);
	printArray(A);
	printf("Deleting At Middle :\n");
	deleteAtMiddle(A);
	printArray(A);
	printf("Deleting At End :\n");
	deleteAtEnd(A);
	printArray(A);
	printf("Inserting at every position :\n");
	insertAtEvery(A,data);
	printArray(A);
	printf("Enter the key to search : ");
	int key;
	scanf("%d",&key);
	printf("The position of %d is %d\n",key,search(A,key));
	printf("Peek Values are : ");
	int c=findPeek(A,p);
	for(int i=0;i<c;i++)
	{
		printf("%d ",p[i]);
	}
}
