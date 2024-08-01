#include <stdio.h>

struct emp
{
	char id;
	int salary;
};

struct pq
{
	struct emp el[100];
	int size;
};

void init(struct pq*p)
{
	p->size=0;
	p->el[0].id = 'Z';
	p->el[0].salary = 10000000;
}

void print (struct pq*p)
{
	for (int i=1;i<=p->size;i++)
	printf ("(%c,%d)\t", p->el[i].id, p->el[i].salary);
}

void insert (struct pq*p, char id, int sal)
{
	int i;
	for (i=++p->size;p->el[i/2].salary<sal;i/=2)
	{
		p->el[i].id = p->el[i/2].id;
		p->el[i].salary = p->el[i/2].salary;
	}
	p->el[i].id = id;
	p->el[i].salary = sal;
}

struct emp deletemax (struct pq*p)
{
	int i,child;
	struct emp maxelt = p->el[1];
	struct emp lastelt = p->el[p->size--];
	for (i=1;(i*2)<=p->size;i=child)
	{
		child = i*2;
		if (p->el[child+1].salary>p->el[child].salary)
		child++;
		if (lastelt.salary < p->el[child].salary)
		p->el[i] = p->el[child];
		else
		break;
	}
	p->el[i] = lastelt;
	return maxelt;
}
