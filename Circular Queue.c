#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define s 5
int q[s],r=-1,f=0;
void insert();
void delete();
bool isFull();
bool isEmpty();
void display();
void main()
{
	int ch;
	while(1)
	{
		printf("Enter the choice=\n1:Insert a element\n2:Delete an element\n3:Display\n4:Exit\n");
		scanf("%d",&ch);
		switch(ch)
=	{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Enter valid input\n");
		}
	}
}

void insert()
{	
	if(isFull())
	{
		printf("Queue Overflow\n");
	}
	else if(r==s-1 && f!=0)
	{
		r=(r+1)%s;
		printf("Enter the element= ");
		scanf("%d",&q[r]);
	}
	else
	{	
		printf("Enter the element= ");
		scanf("%d",&q[++r]);		
	}
}

void delete()
{
	if(isEmpty())
	{
		printf("Queue Underflow\n");
	}
	else if(r==f)
	{
		r=f=-1;
	}

	else
	{
		printf("Removed element=%d\n",q[f++]);
	}
}
void display()
{
	int i;
	if(r>f)
	{
		for(i=f;i<=r;i++)
		{
			printf("\t%d",q[i]);
		}
	}
	else 
	{
		for(i=0;i<=r;i++)
		{
			printf("%d\t",q[i]);
		}
		for(i=f;i<s;i++)
		{
			printf("%d\t",q[i]);
		}
	}
	printf("\n");
}

bool isFull()
{
	if(r==s-1 && f==0)
                return 1;
        else if(f==r+1))
		return 1;
	else 
		return 0;
}
bool isEmpty()
{
	if(r==-1 && f==0)
		return 1;
	else
	 	return 0;
}
