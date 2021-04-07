# Python program for the above approach
import math

# Structure of a Node of a Tree
class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right


# Function to calculate the
# nearest power of an integer
def nearestPow(x, base):
	k = int(math.log(x, base))
	if abs(base**k - x) < abs(base**(k+1) - x):
		return base**k
	else:
		return base**(k+1)

# Iterative method to perform
# Level Order Traversal
def printLevelOrder(root):

	# Base Case
	if root is None:
		return

	# Queue for Level
	# Order Traversal
	q = []

	# Enqueue root
	q.append(root)

	while q:

		# Stores number of
		# nodes at current level
		count = len(q)

		# Dequeue all nodes of the current
		# level and Enqueue all nodes of
		# the next level
		while count > 0:
			temp = q.pop(0)
			print(temp.val, end=' ')

			# Push the left subtree
			# if not empty
			if temp.left:
				q.append(temp.left)

			# Push the right subtree
			# if not empty
			if temp.right:
				q.append(temp.right)

			# Decrement count by 1
			count -= 1


# Function to replace each node
# with nearest power of minimum
# value of previous level
def replaceNodes(root):

	# Stores the nodes of tree to
	# traverse in level order
	que = [root]

	# Stores current level
	lvl = 1

	# Stores the minimum
	# value of previous level
	minPrev = root.val

	# Stores the minimum
	# value of current level
	minCurr = root.val

	# Iterate while True
	while True:

		# Stores length of queue
		length = len(que)

		# If length is zero
		if not length:
			break

		# Assign minPrev = minCurr
		minPrev = minCurr
		minCurr = 1000000000000000000

		# Iterate over range [0, length - 1]
		while length:

			# Stores current node of tree
			temp = que.pop(0)

			# Update minCurr
			minCurr = min(temp.val, minCurr)

			# Replace current node with
			# nearest power of minPrev
			temp.val = nearestPow(temp.val, minPrev)

			# Left child is not Null
			if temp.left:

				# Append temp.left node
				# in the queue
				que.append(temp.left)

			# If right child is not Null
			if temp.right:

				# Append temp.right node
				# in the queue
				que.append(temp.right)

			# Decrement length by one
			length -= 1

		# Increment level by one
		lvl += 1

	# Function Call to perform the
	# Level Order Traversal
	printLevelOrder(root)


# Driver Code

# Given Tree
root = TreeNode(7)
root.left = TreeNode(4)
root.right = TreeNode(11)
root.left.right = TreeNode(23)

replaceNodes(root)
