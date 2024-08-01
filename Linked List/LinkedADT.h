struct node
{
	int data;
	struct node * next;
};

void create(struct node* header,int data)
{
	struct node* temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=header->next;
	header->next=temp;
}

void append(struct node* header,int data)
{
	struct node* temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	struct node* ptr;
	ptr=header->next;
	while((ptr->next)!=NULL)
	{
		ptr=ptr->next;
	}
	temp->next=ptr->next;
	ptr->next=temp;
}

struct node* search(struct node* header,int key)
{																																																																																				
	struct node* ptr;
	ptr=header->next;
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			return ptr;
		}
		ptr=ptr->next;
	}
	return NULL;
}

void insertAtFront(struct node* header,int data)
{
	struct node* temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=header->next;
	header->next=temp;
}

void insertAfter(struct node* header,int data,int key)
{
	struct node* temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	struct node* ptr;
	ptr=search(header,key);
	temp->next=ptr->next;
	ptr->next=temp;
}

void deleteData(struct node* header,int data)
{
	struct node* ptr;
	ptr=header->next;
	while(ptr!=NULL)
	{
		if((ptr->next->data)==data)
		{
			ptr->next=ptr->next->next;
		}
		ptr=ptr->next;
	}
}

void deleteAtFront(struct node *header)
{
	struct node *temp = header->next;
	header->next = temp->next;
	free(temp);
}

void deleteAtEnd(struct node* header)
{
	struct node *temp = header->next;
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	struct node *last = temp->next;
	temp->next = last->next;
}

void display(struct node* header)
{
	struct node* ptr;
	ptr=header->next;
	printf("Linked List => ");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void reverse(struct node * header)
{
	struct node* prev=NULL;
    struct node* curr=header->next;
    struct node* next=NULL;
    while (curr != NULL) 
	{
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    header->next = prev;
}

void printMiddle(struct node* header)
{
    int count=0;
    struct node* mid=header;
    while(header!=NULL)
    {
        if(count & 1)
            mid=mid->next;
        ++count;
        header=header->next;
    }
    if (mid!=NULL)
        printf("The middle element is %d\n",mid->data);
}

int detectLoop(struct node* header)
{
	struct node *ptr1=header->next;
	struct node *ptr2=header;
	while(ptr1!=NULL)
	{
		while(ptr2->next!=ptr1)
		{
			if(ptr2==ptr1->next)
			{
				return 1;
			}
			ptr2=ptr2->next;
		}
		ptr2=header;
		ptr1=ptr1->next;
	}
	return 0;
}
