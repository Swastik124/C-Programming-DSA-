#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next,*prev;
}n;
n *start,*temp=NULL;

void create_list();
void traverse_list();
void at_beginning();
void insert_node();
void at_end();
void delete_beg();
void delete_end_node();
void delete_specific_node();

void main()
{
	int ch;
	while(1)
	{
		printf("Enter the choice=\n1:Create a list\n2:Traverse list\n3:Insert node at a position\n4:At beginning\n5:At end\n6:Delete node from beginning\n7:Delete end node\n8:Delete specific node\n9:Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create_list();
				break;
			case 2:
				traverse_list();
				break;
			case 3:
				insert_node();
				break;
			case 4: 
				at_beginning();
				break;
			case 5:
				at_end();
				break;
			case 6:
				delete_beg();
				break;
			case 7:
				delete_end_node();
				break;
			case 8:
				delete_specific_node();
				break;
			case 9:
				exit(0);
		}
	}
}
void delete_beg()
{
	temp=start;
	if(start==NULL)
		printf("List is Empty\n");
	else
	{
		temp=temp->next;
		start=temp;
		temp->prev=NULL;
	}
}

void delete_end_node()
{
	n *t;
	temp=start;
	while(temp->next!=NULL)
	{
		t=temp;
		temp=temp->next;
	}
	t->next=NULL;
}


void delete_specific_node()
{
	int value;
	n *t;
	printf("The value you want to delete= "); 
	scanf("%d",&value);
	temp=start;
	while(temp->next!=NULL && temp->data!=value)
	{
		t=temp;
		temp=temp->next;
	}
	temp->next->prev=t;
	t->next=temp->next;

}

void create_list()
{
	int i,s,v;
	n *newnode;
	printf("Enter size of nodes= ");
	scanf("%d",&s);
	for(i=0;i<s;i++)
	{
		printf("Value you want to enter= ");
		scanf("%d",&v);
		newnode=(n*)malloc(sizeof(n));
		newnode->data=v;
		newnode->prev=NULL;
		newnode->next=NULL;
		if(start==NULL)
			start=newnode;
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{		        	
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
		}
	}
}
void traverse_list()
{
	n *t;
	temp=start;
	if(start==NULL)
		printf("Empty\n");
	else
	{
		while(temp!=NULL)
		{
			t=temp;
			printf("\t%d",temp->data);
			temp=temp->next;
		}
		printf("\n");
		while(t!=NULL)
		{
			printf("\t%d",t->data);
			t=t->prev;
		}
		printf("\n");
	}
}

void insert_node()
{
	n *p;
	int v,value;
	n *newnode;
	printf("Value after which newnode will be inserted= ");
	scanf("%d",&v);
	printf("Enter the value to be inserted= ");
	scanf("%d",&value);
	newnode=(n*)malloc(sizeof(n));
	newnode->data=value;
	newnode->prev=NULL;
	newnode->next=NULL;
	temp=start;
	while(temp->data!=v)
	{
		p=temp;
		temp=temp->next;
	}	
	newnode->next=temp->next;
	newnode->prev=temp;
	temp->next->prev=newnode;
	temp->next=newnode;
}

void at_beginning()
{
	int value;
	n *newnode;
	newnode=(n*)malloc(sizeof(n));
	printf("Enter value you want to enter= ");
	scanf("%d",&value);
	newnode->data=value;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(start==NULL)
		start=newnode;
	else
	{
		temp=start;
		newnode->next=temp;
		temp->prev=newnode;
		start=newnode;
		
	}	
}

void at_end()
{
	n *newnode;
	int value;
	newnode=(n*)malloc(sizeof(n));
	printf("Enter the value you want to enter= ");
	scanf("%d",&value);
	newnode->data=value;
	newnode->next=NULL;
	newnode->prev=NULL;
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;

}


