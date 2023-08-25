#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define s 5
int top=-1,i;
char a[s];
void push();
void reverse();
bool isfull();
bool isempty();

void main()
{
	int ch;
	while(1)
	{
		printf("Enter the choice=\n1:Push the element\n2:Reverse of the string\n3:Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{																			case 1:
				push();
				break;	
			case 2:
				reverse();
				break;
			case 3:
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
		printf("Enter the String=\n");
		for(i=top;i<s;i++)
		{
			top++;
		        scanf("%c",&a[i]);
		}
	}
}

void reverse()
{
	if(isempty())
	{
		printf("STACK IS EMPTY\nSTACK UNDERFLOW\n");	
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%c",a[i]);
			top--;
		}
		printf("\n");
	}
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

