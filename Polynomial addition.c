#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int coeff,exp;
	struct node *next;
}n;


n *create(n *);
void traverse(n *);
n *add(n*,n*,n*);

void main()
{
	n *p1,*p2,*res;
	p1=p2=res=NULL;
	p1=create(p1);
	printf("1st poly. is:\n");
	traverse(p1);	
	p2=create(p2);
	printf("2nd poly. is:\n");
	traverse(p2);
	res=add(p1,p2,res);
	traverse(res);

}

n *create(n *p1)
{
	int i,s,co,e;
	n *newnode,*temp;
	printf("Enter size of nodes= ");
	scanf("%d",&s);
	for(i=0;i<s;i++)
	{
		printf("Value of coffecient= ");
		scanf("%d",&co);
		printf("Degree= ");
		scanf("%d",&e);
		newnode=(n*)malloc(sizeof(n));
		newnode->coeff=co;
		newnode->exp=e;
		newnode->next=NULL;
		if(p1==NULL)
			p1=newnode;
		else
		{
			temp=p1;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newnode;
		}
	}
	return p1;
}

void traverse(n *p1)
{
	n *temp;
	temp=p1;
	if(p1==NULL)
		printf("Empty List\n");
	else
	{
		while(temp!=NULL)
		{
			printf("\t%dx^%d",temp->coeff,temp->exp);
			temp=temp->next;
		}
		printf("\n");
	}
}

n *add(n *p1,n *p2,n *res)
{
	n *temp1,*temp2,*temp3;
	temp1=p1;
	temp2=p2;
	n *newnode;
	printf("RESULT IS:\n");
	while(temp1!=NULL && temp2!=NULL)
	{
		newnode=(n*)malloc(sizeof(n));
		if(temp1->exp<temp2->exp)
		{
                        newnode->coeff=temp2->coeff;
                        newnode->exp=temp2->exp;
                        newnode->next=NULL;
			temp2=temp2->next;
	        }
		else if(temp1->exp>temp2->exp)
		{
			newnode->coeff=temp1->coeff;
			newnode->exp=temp1->exp;
			newnode->next=NULL;
			temp1=temp1->next;
		}
		else
		{
			newnode->coeff=temp1->coeff+temp2->coeff;
			newnode->exp=temp2->exp;
			newnode->next=NULL;
			temp1=temp1->next;
			temp2=temp2->next;
		}
		if(res==NULL)
		{
			res=newnode;
		}
		else
		{
			temp3=res;
			while(temp3->next!=NULL)
			{
				temp3=temp3->next;
			}
			temp3->next=newnode;
		}
		
	}
	return res;
}	
