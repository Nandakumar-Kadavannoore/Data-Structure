# Python3 program for the above approach

# Function to check if an array
# can be made strictly increasing
def check(arr, n):
	# Traverse the given array arr[]
	for i in range(1, n):

		if (arr[i - 1] >= (i - 1)):

			# Update the value of p,
			# arr[i], and arr[i - 1]
			p = arr[i - 1] - (i - 1)
			arr[i] += p
			arr[i - 1] -= p

	# Traverse the given array
	for i in range(1, n):
		# Check if the array arr[] is
		# strictly increasing or not
		if (arr[i] <= arr[i - 1]):

			print ("No")
			return


	# Otherwise, array is increasing
	# order, prYes
	print ("Yes")

# Driver Code
if __name__ == '__main__':
	arr = [1, 5, 2, 7, 6]
	N = len(arr)
	check(arr, N)
