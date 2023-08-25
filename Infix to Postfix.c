#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char infix[20];
char stack[20];
int top=-1;

void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    if(top==-1)
    {
        printf("\nStack is now empty");
        exit(1);
    }
    else{
        top--;
    }
}
int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+' || '-')
        return 1;
    if(x=='*' || '/')
        return 2;
    if(x=='^')
        return 3;
}
int main()
{
    char x,*e;
    printf("Enter the infix expression= ");
    scanf("%[^\n]",infix);
    e=infix;
    while(*e != '\0')
    {
        if(isalnum(*e))
             printf("%c",*e);
        else if(*e=='(')
             push(*e);
        else if(*e==')')
             while((x=pop())!='(')
                  printf("%c",x);
        else
        {
            while(priority(stack[top])>=priority(*e))
                    printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
}