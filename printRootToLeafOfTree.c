/* To print out all of its root to leaf paths one per line */

#include<stdio.h>
#include<stdlib.h>

struct linked
{
	int data;
	struct linked *left;
	struct linked *right;
};
typedef struct linked tree;

void show(int x[],int n)
{
	int i=0;
	while(i<n)
	{
		printf(" %d",x[i]);
		i++;
	}
	printf("\n");
}

void printout(tree* root,int x[],int pathlen)
{
	
	if(root!=0)
	{
		x[pathlen]=root->data;
		pathlen++;
	}
	if(root->left==0&&root->right==0)
	  {
	  	show(x,pathlen);
	  	return;
	  }
	else
	  {
	  	printout(root->left,x,pathlen);
	  	printout(root->right,x,pathlen);
	  }  
	  
}

tree* newt()
{
	tree *temp=(tree*)malloc(sizeof(tree));
	temp->right=temp->left=0;
	printf("\nEnter data");
	scanf("%d",&temp->data);
	
	return temp;
}

void display(tree *list)
{
	if(list!=0)
	{
		display(list->left);
		printf(" %d",list->data);
		display(list->right);
	}
}

int main()
{
	int x[45],pathlen=0;
	tree *t1,*t2;
	t1=newt();
	t1->left=newt();
	t1->right=newt();
	t1->left->left=newt();
	t1->left->right=newt();
	printf("\nDisplaying tree(inorder):: ");
	display(t1);
	
	printf("\nDisplaying level order\n");
	
	printout(t1,x,pathlen);
	

	return 0;
}

