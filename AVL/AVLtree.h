struct tree
{
	char data;
	struct tree *left,*right;
	int height;
};
int height(struct tree *t)
{
	if(t==NULL)
		return -1;
	else
		return t->height;
}

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

struct tree* singlerotateleft(struct tree *k2)
{
	struct tree *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left),height(k2->right)) + 1;
	k1->height = max(height(k1->left),height(k1->right)) + 1;
	return k1;
}

struct tree* singlerotateright(struct tree *k1)
{
	struct tree *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(height(k1->left),height(k1->right)) + 1;
	k2->height = max(height(k2->left),height(k2->right)) + 1;
	return k2;
}

struct tree* findParent(struct tree* t,char key)
{
    if (t->left==NULL && t->right==NULL)
        return NULL;
    else if (t->left->data==key || t->right->data==key) 
	{
        return t;
    }
    else if (t->data>key)
	{
        findParent(t->left, key);
    }
	else if (t->data<key)
	{
		findParent(t->right, key);
	}
}

void hierarchical(struct tree *t, int space)
{
	if(t == NULL) 
		return;
	space+=1;
	hierarchical(t->right, space);
	printf("\n");
	for(int i = 0 ; i < space; i++)
	{
		printf("\t");
	}
	printf("%c\n", t->data);
	hierarchical(t->left, space);
}

struct tree *doublerotateleft(struct tree * k1)
{
	k1->left = singlerotateright(k1->left);
	return singlerotateleft(k1);
}

struct tree *doublerotateright(struct tree * k1)
{
	k1->right  = singlerotateleft(k1->right);
	return singlerotateright(k1);
}

struct tree* insert(struct tree *t,char x)
{
	if(t==NULL)
	{
		t=(struct tree *)malloc(sizeof(struct tree));
		t->data=x;
		t->height=0;
		t->left=t->right=NULL;
	}
	else if(x<t->data)
	{
		t->left=insert(t->left,x);
		if(height(t->left)-height(t->right)==2)
		{
			if(x<t->left->data)
				t=singlerotateleft(t);
			else
				t=doublerotateleft(t);
		}
	}
	else if(x>t->data)
	{
		t->right=insert(t->right,x);
		if(height(t->right)-height(t->left)==2)
		{
			if(x>t->right->data)
				t=singlerotateright(t);
			else
				t=doublerotateright(t);
		}
	}
	t->height=max(height(t->left),height(t->right))+1;
	return t;
}

