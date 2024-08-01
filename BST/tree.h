struct node
{
	int data;
	struct node * next;
};

void append(struct node* header,int data)
{
	struct node* temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	struct node *ptr,*end;
	ptr=header->next;
	end=header;
	while(ptr!=NULL)
	{
		end=ptr;
		ptr=ptr->next;
	}
	temp->next=end->next;
	end->next=temp;
}

struct tree
{
	int data;
	struct tree *left,*right;
};

struct tree * insert(struct tree *t, int data)
{
	if(t==NULL)
	{
		t=(struct tree *)malloc(sizeof(struct tree));
		t->data=data;
		t->right=NULL;
		t->left=NULL;
	}
	if(data>t->data)
	{
		t->right=insert(t->right,data);
	}
	if(data<t->data)
	{
		t->left=insert(t->left,data);
	}
	return t;
}

void inorder(struct tree *t)
{
	if (t==NULL)
		return;
	if(t->left!=NULL)
	{
		inorder(t->left);
	}
	printf(" %d",t->data);
	if(t->right!=NULL)
	{
		inorder(t->right);
	}
}

void inorder1(struct tree *t,struct node *h)
{
	if (t==NULL)
		return;
	if(t->left!=NULL)
	{
		inorder1(t->left,h);
	}
	append(h,t->data);
	if(t->right!=NULL)
	{
		inorder1(t->right,h);
	}
}

void postorder(struct tree *t)
{
	if (t==NULL)
		return;
	if(t->left!=NULL)
	{
		postorder(t->left);
	}
	if(t->right!=NULL)
	{
		postorder(t->right);
	}
	printf(" %d",t->data);
}

void preorder(struct tree *t)
{
	if (t==NULL)
		return;
	printf(" %d",t->data);
	if(t->left!=NULL)
	{
		preorder(t->left);
	}
	if(t->right!=NULL)
	{
		preorder(t->right);
	}
}

struct tree * findmin(struct tree *t)
{
	if(t->left==NULL)
	{
		return t;
	}
	findmin(t->left);
}

struct tree * delete(struct tree *t,int data)
{
	struct tree *temp;
	if(data<t->data)
	{
		t->left=delete(t->left,data);
	}
	else if(data>t->data)
	{
		t->right=delete(t->right,data);
	}
	else if(t->left && t->right)
	{
		temp=findmin(t->right);
		t->data=temp->data;
		t->right=delete(t->right,temp->data);
	}
	else
	{
		temp=t;
		if(t->right==NULL)
		{
			t=t->left;
		}
		else if(t->left==NULL)
		{
			t=t->right;
		}
		free(temp);
	}
	return t;
}	

struct tree* search(struct tree* t, int key)
{
  if(t==NULL || t->data==key)
  	return t;
  if(key<t->data)
  	return search(t->left,key);
  if(key>t->data)
  	return search(t->right,key);
}

int height(struct tree* t)
{
    if (t == NULL)
        return 0;
    else 
    {
        int lheight = height(t->left);
        int rheight = height(t->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void level (struct tree* t, int l)
{
  if (t==NULL)
      return;
  if (l==1)
      printf("%d ", t->data);
  else if (l>1) 
  {
      level(t->left, l-1);
      level(t->right, l-1);
  }
}