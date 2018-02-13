/* To convert postfix to infix */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

char postfix[56];
char stack[56];
int top=0;

char pop()
 { top--;
   return(stack[top]); }

void push(char z)
 {
  stack[top]=z;
  top++;
 }

void evaluate(char postfix[])
 {
  int i;    char a,b;
   for(i=0;postfix[i]!='\0';i++)
     {  
       if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/')
	       { a=pop();
	         b=pop();
	         printf("%c%c%c",b,postfix[i],a);
         } else{ 
           push(postfix[i]);
         }
      }
  }

void main()
 { printf("\nEnter postfix:: ");
   scanf("%s",postfix);
   evaluate(postfix);
   getch();
 }
