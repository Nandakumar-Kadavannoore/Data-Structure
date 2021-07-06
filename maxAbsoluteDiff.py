# Python program for the above approach

# Recursive function to find the maximum
# absolute displacement from origin by
# performing the given set of moves


def DistRecursion(S, i, dist):

	# If i is equal to N
	if i == len(S):
		return abs(dist)

	# If S[i] is equal to 'L'
	if S[i] == 'L':
		return DistRecursion(S, i + 1, dist-1)

	# If S[i] is equal to 'R'
	if S[i] == 'R':
		return DistRecursion(S, i + 1, dist + 1)

	# If S[i] is equal to '?'
	return max(DistRecursion(S, i + 1, dist-1),
			DistRecursion(S, i + 1, dist + 1))


# Function to find the maximum absolute
# displacement from the origin
def maxDistance(S):

	# Return the maximum absolute
	# displacement
	return DistRecursion(S, 0, 0)

# Driver Code


# Input
S = "?RRR?"

# Function call
print(maxDistance(S))
