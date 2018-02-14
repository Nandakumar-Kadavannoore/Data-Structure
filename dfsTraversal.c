// To perform dfs traversal in tree
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *l,*r;
};

typedef struct node node;

void insert(node **head,int num)
 {
 	node *temp=*head,*prev=*head;
 	if(*head==0)
 	 {
 	 	*head=(node*)malloc(sizeof(node));
 	 	(*head)->data=num;
 	 	(*head)->l=(*head)->r=0;
 	 }
 	else
	  {
	  	while(temp!=0)
	  	  {
	  	  	    if(num>temp->data)
	  	  	     {
	  	  	     	prev=temp;
	  	  	     	temp=temp->r;
	  	  	     }
	  	  	    else
					 {
					 	 prev=temp;
					 	 temp=temp->l;
					 } 
	  	  }
	  	 temp=(node*)malloc(sizeof(node));
		   temp->data=num;
		 temp->l=temp->r=0;
		if(num>=prev->data)
		    prev->r=temp;
		else
		    prev->l=temp;	    
	  } 
 }

void del(node **head)
 {
 	if(*head==0)
 	  return;
 	else
	  {
	  	  del(&(*head)->l);
	  	  del(&(*head)->r);
	  	  free(*head);
	  }  
 }
 
void dfs(node *head)
 {
 	if(head)
 	  {
 	  	 if(head->l)
 	  	    dfs(head->l);
 	  	 if(head->r)
			 dfs(head->r);
	     printf(" %d",head->data);		    
 	  }
 	  
 } 
 
 
int main()
{
	node *head=0;
	int ch,num;
	do
	{
		printf("\nEnter ur choice\n1] Insert\n2] Dfs\n 3] Delete\nEnter choice:: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : printf("\nEnter element:: ");
			        scanf("%d",&num);
			        insert(&head,num);
			        break;
			case 2 : dfs(head);
			          break;
			         
			case 3 : del(&head);
			         break;
			default: printf("\nNot vaild option");		 		         
		}
		
	}while(ch!=3);
	return 0;
}
