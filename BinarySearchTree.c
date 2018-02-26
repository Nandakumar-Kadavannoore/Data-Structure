// To create bst
#include<stdio.h>
#include<stdlib.h>

struct bt
{
	int data;
	struct bt *l,*r;
};
typedef struct bt tree;


void insert(tree *root,tree *r1)
 {
 	if(root->data>r1->data)
 	  {
 	  	 if(root->l==0)
 	  	    root->l=r1;
 	  	 else
			insert(root->l,r1);   
 	  }
 	 if(root->data<r1->data)
	   {
	   	 if(root->r==0)
	   	    root->r=r1;
	   	 else
			insert(root->r,r1);   
	   } 
 	
 }


void inorder( tree *root )
 {
 	 if(root!=0)
 	  {
 	  	inorder(root->l);
 	  	printf("%d->",root->data);
 	  	inorder(root->r);
 	  }
 }

int main()
 {
 	tree *root=0,*new1;
 	int n;
 	printf("\nEnter element ( 0 to exit ):: ");
 	while(1)
 	 {
 	 	scanf("%d",&n);
 	 	if(n==0)
 	 	  break;
 	 	new1 = (tree*)malloc(sizeof(tree));
		  new1 -> l = new1 -> r = 0;
		  new1 -> data = n;
		if(root==0)
		  root=new1;
		else
		  insert(root,new1);      
 	 }
 	 printf("\nInorder tree traversal:: ");
 	 inorder(root);
 	 return 0;
 }
