#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define s 5
int top=-1;
int a[s],i;
void push();
void pop();
void display();
bool isfull();
bool isempty();

void main()
{
	int ch;
        while(1)
	{
		printf("Enter the choice=\n1:Push the element\n2:Pop the element\n3:Display the element\n4:Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
		        case 2:
			        pop();
				break;
		        case 3:
			        display();
				break;
			case 4:
				exit(0);
			default:
				printf("Enter valid input");
				break;
		}
	}
}
void push()
{
	if(isfull())
	{
		printf("STACK IS FULL");
	}
	else
	{
		top++;
		printf("Enter the element to push=\n");
		scanf("%d",&a[top]);
	}
}
void pop()
{
	if(isempty())
	{
		printf("STACK IS EMPTY\nSTACK UNDERFLOW");	
	}
	else
	{
		printf("The popped element=%d",a[top]);
		top--;
	}
}
void display()
{
	printf("Displaying the elements= \n");
	for(i=0;i<s;i++)
	{
		printf("\t%d",a[i]);
	}
	printf("\n");
}


bool isfull()
{
	if(top==s-1)
		return 1;
	else 
		return 0;
}
bool isempty()
{
	if(top==-1)
		return 1;
	else
	       	return 0;
}
