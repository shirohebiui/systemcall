/*** doubly linked list ***/

#include <stdio.h>
#include <stdlib.h>

typedef struct _double_node
{
	int key;
	struct _double_node *prev;
	struct _double_node *next;
} double_node;

double_node *head, *tail;

void init_dlist(void)
{
	head = (double_node*)malloc(sizeof(double_node));
	tail = (double_node*)malloc(sizeof(double_node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

/*
double_node *find_double_node(int k)
{
	double_node *find;
	find=head->next;
	while(find != tail)
	{
		if( k == find->key) return find;
		find = find->next;
	}
	return find;
	//return == tail > fail
}

int delete_double_node(int k)
{
	double_node *s;
	s = find_double_node(k);
	s->prev->next = s->next;
	s->next->prev = s->prev;
	free(s);
	return 0;
	//return 0 > success
}

double_node *insert_double_node(int k, int t) //insert k, before t
{
	double_node *s;
	double_node *i = NULL;
	s = find_double_node(t); //find node key = t
	
	i->key = k;
	i->prev = s;
	i->next = s->next;
	s->next->prev = i;
	s->next = i;

	return i;
}
*/
double_node *Insert_double_node_in_order_of_size(int k)
{
	double_node *s;
	double_node *i;
	if(head->next == tail)
	{
		i->key = k;
		i->prev = head;
		i->next = tail;
		head->next = i;
		tail->prev = i;
	}
	else 
	{
		s=head->next;
		while(s != tail)
		{
			if( k < s->key || (s == tail) )
			{
				i->key = k;
				i->prev = s->prev;
				i->next = s;
				s->prev->next = i;
				s->prev = i;
			}
			else	s = s->next;
		}
	}
	return i;
}
/*	
int delete_double_node_ptr(double_node *p)
{
	if(p==head || p==tail)
		return 0;
	
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);

	return 1;
}

double_node *insert_double_node_ptr(int k, double_node *t)
{
	double_node *i;
	i->key = k;
	i->prev = t->prev;
	i->next = t;
	t->prev->next = i;
	t->prev = i;
}
*/
void print_all(double_node *p)
{
	while(p != tail)
	{
		printf("%d\t", p->key);
		p=p->next;
	}
	printf("\n");
}
/*
void delete_all_double_nodes(void)
{
	while(head->next != tail)
	{
		head->next=head->next->next;
		free(head->next->prev);
	}
}
*/
void main(void)
{
	double_node *t;
	init_dlist();

	Insert_double_node_in_order_of_size(10);
	Insert_double_node_in_order_of_size(5);
	Insert_double_node_in_order_of_size(8);
	Insert_double_node_in_order_of_size(3);
	Insert_double_node_in_order_of_size(1);
	Insert_double_node_in_order_of_size(7);
	Insert_double_node_in_order_of_size(8);

	printf("\n Initial Linked list is ");
	print_all(head->next);
/*	
	printf("\n Finding 4 is %ssuccessful", find_double_node(4) == tail ? "un" : "");

	t = find_double_node(5);
	printf("\n Finding 5 is %ssuccessful", t == tail ? "un" : "");
	
	printf("\n Inserting 7 before 5");
	insert_double_node_ptr(7, t);
	print_all(head->next);

	t = find_double_node(3);
	printf("\n Deleting 3 ");
	delete_double_node_ptr(t);
	print_all(head->next);

	printf("\n Inserting node 2 before 10");
	insert_double_node(2, 10);
	print_all(head->next);

	printf("\n Deleting node 2");
	if (!delete_double_node(2))
		printf("\n deleting 2 is unsuccessful");
	print_all(head->next);

	printf("\nDeleting node 1");
	delete_double_node(1);
	print_all(head->next);

	printf("\nInserting 15 at first");
	insert_double_node_ptr(15, head->next);
	print_all(head->next);

	printf("\nDeleting all node");
	delete_all_double_nodes();
	print_all(head->next);
*/
}











