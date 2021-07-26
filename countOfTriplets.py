# Python program for the above approach

# Fuction to find the SPF[i] using the
# Sieve Of Erastothenes
def sieveOfEratosthenes(N, s):
	
	# Stores whether i is prime or not
	prime = [False] * (N + 1)
	
	# Initializing smallest factor as
	# 2 for all even numbers
	for i in range(2, N + 1, 2):
		s[i] = 2
	
	# Iterate for all odd numbers < N
	for i in range(3, N + 1, 2):
		if (prime[i] == False):
			
			# SPF of i for a prime is
			# the number itself
			s[i] = i
	
			# Iterate for all the multiples
			# of the current prime number
			for j in range(i, int(N / i) + 1, 2):
				if (prime[i * j] == False):
					prime[i * j] = True
					
					# The value i is smallest
					# prime factor for i * j
					s[i * j] = i

# Function to generate prime factors
# and its power
def generatePrimeFactors(N):
	
	# Current prime factor of N
	curr = s[N]
	
	# Stores the powers of the current
	# prime factor
	cnt = {s[N]:1}
	
	# Find all the prime factors and
	# their powers
	while (N > 1):
	
		N //= s[N]
		if N and s[N]:
			if cnt.get(s[N], 0) == 0:
				cnt[s[N]] = 1
			else:
				cnt[s[N]] += 1
	
	if 0 in cnt:
		cnt.pop(0)
		
	totfactor = 1
	
	for i in cnt.values():
		totfactor *= i + 1
	
	# Return the total count of factors
	return totfactor

# Function to count the number of triplets
# satisfying the given criteria
def countTriplets(N):
	
	# Stores the count of resultant triplets
	CountTriplet = 0
	
	for z in range(1, N + 1):
		
		# Add the count all factors of N-z
		# to the variable CountTriplet
		p = generatePrimeFactors(N-z)
		if p > 1:
			CountTriplet += p
	
	# Return total count of triplets
	return CountTriplet + 1	
	

# Driver Code
N = 10

# S[i] stores the smallest prime factor
# for each element i
s = [0] * (N + 1)

# Find the SPF[i]
sieveOfEratosthenes(N, s)

# Fuction Call
print(countTriplets(N))
