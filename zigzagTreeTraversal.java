// Java program to print zigzag 
// traversal of a binary tree 
// using Recursion 

class GfG 
{ 

// Binary tree node 
static class node 
{ 
	node left; 
	node right; 
	int data; 
} 

// Function to create a new 
// Binary Tree Node 
static node newNode(int data) 
{ 
	node temp = new node(); 

	temp.data = data; 
	temp.left = null; 
	temp.right = null; 

	return temp; 
} 

// Recursive Function to find height 
// of binary tree 
static int heightOfTree(node root) 
{ 
	if(root == null) 
	return 0; 
	
	int lheight = heightOfTree(root.left); 
	int rheight = heightOfTree(root.right); 
	
	return Math.max(lheight + 1 ,rheight + 1); 
} 

// Function to print nodes from right to left 
static void printRightToLeft(node root ,int level) 
{ 
	if(root == null) 
	return; 
	
	if(level == 1) 
	System.out.print(root.data + " ") ; 
	
	else if(level > 1) 
	{ 
		printRightToLeft(root.right ,level - 1); 
		printRightToLeft(root.left ,level - 1); 
	} 
} 

// Function to print nodes from left to right 
static void printLeftToRight(node root ,int level) 
{ 
	if(root == null) 
	return; 
	
	if(level == 1) 
	System.out.print(root.data + " ") ; 
	
	else if(level > 1) 
	{ 
		printLeftToRight(root.left ,level - 1); 
		printLeftToRight(root.right ,level - 1); 
	} 
} 

// Function to print Reverse ZigZag of 
// a Binary tree 
static void printZigZag(node root ) 
{ 
	// Flag is used to mark the change 
	// in level 
	int flag = 0; 
	
	// Height of tree 
	int height = heightOfTree(root); 
	
	for(int i = 1 ; i <= height ; i++) 
	{ 
		// If flag value is one print nodes 
		// from right to left 
		if(flag == 1) 
		{ 
			printRightToLeft(root ,i); 
			
			// Mark flag as zero so that next time 
			// nodes are printed from left to right 
			flag = 0; 
		} 
		// If flag is zero print nodes 
		// from left to right 
		else if(flag == 0) 
		{ 
			printLeftToRight(root ,i); 
			
			// Mark flag as one so that next time 
			// nodes are printed from right to left 
			flag = 1; 
		} 
	} 
} 

// Driver code 
public static void main(String[] args) 
{ 
	node root = newNode(7); 
	root.left = newNode(4); 
	root.right = newNode(5); 
	root.left.left = newNode(9); 
	root.right.right = newNode(10); 
	root.left.left.left = newNode(6); 
	root.left.left.right = newNode(11); 
	
	printZigZag(root); 
} 
} 

