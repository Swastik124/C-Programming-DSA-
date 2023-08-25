#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
int a[10],top=-1;
void main()
{
	int r,n;
	printf("Enter the number for convertion=");
	scanf("%d",&n);
	while(n!=0)
	{
		r=n%2;
		push(r);
		n=n/2;	
	}
	while(top!=-1)
	{
		pop();
		
	}
}
void push(int r)
{
	if(r==0)
	{
		a[++top]=0;
	}
	else
	{
		a[++top]=1;
	}
}
void pop()
{
	printf("%d",a[top--]);
}
