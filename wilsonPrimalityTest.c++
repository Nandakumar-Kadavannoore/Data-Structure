// Function to calculate the factorial 
long fact(const int& p) 
{ 
    if (p <= 1) 
        return 1; 
    return p * fact(p - 1); 
} 
  
// Function to check if the 
// number is prime or not 
bool isPrime(const int& p) 
{ 
    if (p == 4) 
        return false; 
    return bool(fact(p >> 1) % p); 
} 
