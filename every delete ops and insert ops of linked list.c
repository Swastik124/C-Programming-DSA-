#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node *next;
}n;

n *start,*temp=NULL;
void create();
void traverse();
void at_beginning();
void at_end();
void at_specific_pos();
void after_that_pos();
void delete_specific_node();
void delete_beginning_node();
void delete_end_node();
void delete_after_node();

void main()
{
	int ch;
	while(1)
	{
		printf("Enter the choice:\n1: Create the Linked List\n2: Traverse The Linked List\n3: Insert the node at beginning\n4: At end\n5: At a specific position\n6: After that specific position\n7: delete specific node\n8: delete beginning node\n9: delete end node\n10: delete after a specific node\n11:Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				traverse();
				break;
			case 3:
				at_beginning();
				break;
			case 4:
				at_end();
				break;
			case 5:
				at_specific_pos();
				break;
			case 6:
				after_that_pos();
				break;
			case 7:
				delete_specific_node();
				break;
			case 8:
				delete_beginning_node();
				break;
			case 9:
				delete_end_node();
				break;
			case 10:
				delete_after_node();
				break;
			case 11:
				exit(0);
			default:
				printf("Enter Valid Input\n");
	        }
	}
}
void delete_beginning_node()
{
	temp=start;
	if(start==NULL)
		printf("List is Empty\n");
	else
	{
		temp=temp->next;
		start=temp;
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

void delete_after_node()
{
	n *t,*p;
	int value;
	printf("Enter the value after which you will delete the node= ");
	scanf("%d",&value);
	temp=start;
	while(temp->data!=value && temp->next!=NULL)
	{ 	        
		temp=temp->next;
		p=temp;
       	}
	temp=temp->next;
	t=temp;
	p->next=t->next;
	
}

void create()
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
		newnode->next=NULL;
		if(start==NULL)
			start=newnode;
		else
		{
			temp=start;
			while(temp->next!=NULL)	
				temp=temp->next;
			temp->next=newnode;
		}
	}
}
void traverse()
{
	temp=start;
	if(start==NULL)
		printf("Empty List\n");
	else
	{
		while(temp!=NULL)
		{
			printf("\t%d",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void delete_specific_node()
{
	int value;
	n *t;
	printf("The value you want to delete= "); 
	scanf("%d",&value);
	temp=start;
	while(temp->data!=value)
	{
		t=temp;
		temp=temp->next;
	}
	t->next=temp->next;
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
	if(start==NULL)
		start=newnode;
	else
	{
		newnode->next=start;
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
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
}
void at_specific_pos()
{
	n *newnode;
	int value,loc;
	int count=1;
	printf("Enter the location where you want to enter= ");
	scanf("%d",&loc);
	newnode=(n*)malloc(sizeof(n));
	printf("Enter value you want to enter= ");
	scanf("%d",&value);
	newnode->data=value;
	newnode->next=NULL;
	temp=start;
	while(temp->next!=NULL && count!=loc)
	{
		count++;
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void after_that_pos()
{
	n *newnode;
	int value,d_value;
	printf("The value after which you want to enter the new node= ");
	scanf("%d",&d_value);
	newnode=(n*)malloc(sizeof(n));
	printf("Enter the value you want to enter= ");
	scanf("%d",&value);
	newnode->data=value;
 	newnode->next=NULL;
	temp=start;
	while(temp->next!='\0' && temp->data!=d_value)
	{
		temp=temp->next;
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
