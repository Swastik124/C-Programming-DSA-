#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}n;

n *start,*temp=NULL;

void create_list();
void traverse_list();
void insert_node();
void delete_specific_node();

void main()
{
	int ch;
	while(1)
	{
		printf("Enter the choice=\n1:Create a list\n2:Traverse list\n3:Insert node at a position\n4:Delete specific node\n5:Exit\n");
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
				delete_specific_node();
				break;
			case 5:
				exit(0);
		}
	}
}

void create_list()
{
	int i,s,v,j;
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
		{
			start=newnode;
			newnode->next=start;
		}
		else
		{ 
			temp=start;
			while(temp->next!=start)
				temp=temp->next;
			temp->next=newnode;
			newnode->next=start;
		}
	}
}

void traverse_list()
{
	temp=start;
	if(start==NULL)
		printf("Empty\n");
	else{
		while(temp->next!=start)
		{
			printf("\t%d",temp->data);
			temp=temp->next;
		}
		printf("\t%d\n",temp->data);
	}
}

void insert_node()
{
	n *newnode;
	int v,value;
	newnode=(n*)malloc(sizeof(n));
	printf("Enter the value after which value will be inserted= ");
	scanf("%d",&v);
	printf("Enter value you want to enter= ");
	scanf("%d",&value);
	newnode->data=value;
	newnode->next=NULL;
	temp=start;
	while(temp->data!=v)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}

void delete_specific_node()
{
	int value,count=0;
	n *t;
	printf("The value you want to delete= "); 
	scanf("%d",&value);
	temp=start;
	if(temp->next==start)
	{
		start=NULL;
		printf("List is now Empty\n");
	}
	else
	{
		while(temp->data!=value)
	        {	
			count++;
		        t=temp;
		        temp=temp->next;
	        }
		if(count==0)
		{
			temp=start;
			while(temp->next!=start)
			{
				temp=temp->next;
			}
			temp->next=start->next;
			start=start->next;
		}
		else
		{
			t->next=temp->next;
		}
	}
}
