# Python3 program for the above approach
 
# Structure of a Binary Tree Node
class Node:
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None
         
# Function to find the depth of
# a given node in a Binary Tree
def findDepth(root, x):
   
    # Base case
    if (root == None):
        return -1
 
    # Initialize distance as -1
    dist = -1
 
    # Check if x is current node=
    if (root.data == x):
        return dist + 1
 
    dist = findDepth(root.left, x)
    if dist >= 0:
        return dist + 1
    dist = findDepth(root.right, x)
    if dist >= 0:
        return dist + 1
    return dist
 
# Helper function to find the height
# of a given node in the binary tree
def findHeightUtil(root, x):
    global height
 
    # Base Case
    if (root == None):
        return -1
 
    # Store the maximum height of
    # the left and right subtree
    leftHeight = findHeightUtil(root.left, x)
 
    rightHeight = findHeightUtil(root.right, x)
 
    # Update height of the current node
    ans = max(leftHeight, rightHeight) + 1
 
    # If current node is the required node
    if (root.data == x):
        height = ans
 
    return ans
 
# Function to find the height of
# a given node in a Binary Tree
def findHeight(root, x):
    global height
 
    # Stores height of the Tree
    maxHeight = findHeightUtil(root, x)
 
    # Return the height
    return height
 
# Driver Code
if __name__ == '__main__':
   
    # Binary Tree Formation
    height = -1
    root = Node(5)
    root.left = Node(10)
    root.right = Node(15)
    root.left.left = Node(20)
    root.left.right = Node(25)
    root.left.right.right = Node(45)
    root.right.left = Node(30)
    root.right.right = Node(35)
 
    k = 25
 
    # Function call to find the
    # depth of a given node
    print("Depth: ",findDepth(root, k))
 
    # Function call to find the
    # height of a given node
    print("Height: ",findHeight(root, k))
 
