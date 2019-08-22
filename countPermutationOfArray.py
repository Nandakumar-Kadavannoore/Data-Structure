# Python implementation of the approach 

# Recursive function that returns 
# the count of permutation-based 
# on the length of the array. 

def count(n): 
	if n == 0: 
		return 1
	if n == 1: 
		return 1
	else: 
		return (n * count(n-1)) + ((n-1) * count(n-2)) 

# Driver Code 
A =[1, 2, 3, 9] 
print(count(len(A)-1)) 
