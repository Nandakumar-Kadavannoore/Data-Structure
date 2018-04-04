/* To implement circular queue */

#include<stdio.h>
#define max 5

int front=-1,rear=-1;

void deque(int x[])
{
	if(front==-1)
	{
		printf("\nQueue underflow");
		return;
	}
	printf("%d dequeued",x[front]);
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	  front=(front+1)%max;
}

void enque(int x[])
{
	if(front==(rear+1)%max)
	 {
	 	printf("\nQueue Overflow");
	 	return;
	 }
	else
	{   if(front==-1)
	      front=rear=0;
	    else  
		 rear=(rear+1)%max;
	int data;
	printf("\nEnter data:) ");
	scanf("%d",&data);
	x[rear]=data;
    }
}

void display(int x[])
{
	int i;
	for(i=front;i!=rear;i=(i+1)%max)
	 printf(" %d",x[i]);
	printf(" %d",x[i]); 
}

int main()
{
	int choice,x[max];
	do{
		printf("\nMain_Menu\n");
		printf("1.Enque\n2.Deque\n3.Display\n4.Quit");
		printf("\nEnter ur choice:: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: enque(x); break;
			case 2: deque(x); break;
			case 3: display(x); break;
			default: printf("\nTry Again");
		}
	}while(choice!=4);
}
