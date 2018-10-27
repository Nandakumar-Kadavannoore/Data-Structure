class MainClass { 
  
    // Function to check if a number is prime or not 
    static boolean isPrime(int n) 
    { 
        // Corner cases 
        if (n <= 1) 
            return false; 
        if (n <= 3) 
            return true; 
  
        // This is checked so that we can skip 
        // middle five numbers in below loop 
        if (n % 2 == 0 || n % 3 == 0) 
            return false; 
  
        for (int i = 5; i * i <= n; i = i + 6) { 
            if (n % i == 0 || n % (i + 2) == 0) { 
                return false; 
            } 
        } 
        return true; 
    } 
  
    // Utility function to check power of two 
    static boolean isPowerOfTwo(int n) 
    { 
        return n != 0 && ((n & (n - 1)) == 0); 
    } 
  
    // Driver Program 
    public static void main(String[] args) 
    { 
        int n = 43; 
  
        // Check if number is prime 
        // and of the form ( 2^q +1 )/3 
        if (isPrime(n) && (isPowerOfTwo(n * 3 - 1))) { 
            System.out.println("YES"); 
        } 
        else { 
            System.out.println("NO"); 
        } 
    } 
} 
