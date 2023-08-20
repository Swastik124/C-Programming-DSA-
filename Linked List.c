#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *start,*temp=NULL;
void create_list()
{
	int i,n;
	int ch;
	node *newnode,*temp;
	printf("Enter the no. of nodes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(node*)malloc(sizeof(node));
		printf("Enter a value= ");
		scanf("%d",&ch);
		newnode->data=ch;
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
void traverse_list()
{
	node *temp;
	temp=start;
	if(start==NULL)
		printf("empty");
	else{
		while(temp!=NULL)
		{
			printf("\t%d",temp->data);
			temp= temp->next;
		}
	printf("\n");
	}
}
void main()
{
	create_list();
	traverse_list();
}

