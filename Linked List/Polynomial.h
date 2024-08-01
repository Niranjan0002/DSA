struct node 
{
    int coef;
    int exp;
    struct node *next;
};

void insert(struct node *header, int coef, int exp) 
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->coef=coef;
    temp->exp=exp;
    temp->next=NULL;
    if(header->next==NULL) 
    {
        header->next=temp;
    } 
    else 
    {
        struct node *current=header->next;
        while (current->next!=NULL) 
        {
            current=current->next;
        }
        current->next=temp;
    }
}

void display(struct node *p) 
{
    struct node *current=p->next;
    while(current!=NULL) 
    {
        printf("%dx^%d",current->coef,current->exp);
        current=current->next;
        if (current!=NULL) 
        {
            printf(" + ");
        }
    }
    printf("\n");
}

void add(struct node* p1, struct node* p2, struct node* sum) 
{
    int flag;
    struct node* t=sum;
    while (p1->next!=NULL) 
    {
        insert(sum,p1->next->coef,p1->next->exp);
        p1=p1->next;
    }
    while (p2->next!=NULL)
    {
        flag=0;
        sum=t;
        while (sum->next!=NULL) 
        {
            if(p2->next->exp==sum->next->exp)
            {
                flag=1;
                sum->next->coef=sum->next->coef+p2->next->coef;
            }
            sum=sum->next;
        }
        if(flag==0)
        {
            insert(sum,p2->next->coef,p2->next->exp);
        }
        p2=p2->next;
    }
}
