# Python3 program for finding value
# of continuous floor function

max = 10000

dp = [0] * max

# function to initialize the DP array
def initDP() :
	
		for i in range(max) :
				dp[i] = -1
	
# function to return value of F(n)
def func(x) :

	if (x == 0) :
		return 0
		
	if (dp[x] == -1) :
		dp[x] = x + func(x // 2)

	return dp[x]
	
def printFloor(arr, n) :
	
	for i in range(n) :
				
		print(func(arr[i]), end = " ")

# Driver Code
if __name__ == "__main__" :

		# call the initDP() to
		# fill DP array		
		initDP()

		arr = [8, 6]
		n = len(arr)

		printFloor(arr, n)

# This code is contributed by Ryuga
