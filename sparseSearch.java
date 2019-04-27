// Java program to implement binary search 
// in a sparse array. 

class solution 
{ 

// Binary Search in an array with blanks 
static int binarySearch(String arr[], int low, int high, String x) { 
if (low > high) 
	return -1; 

int mid = (low + high) / 2; 

//Modified Part 
if (arr[mid] == "") { 
	int left = mid - 1; 
	int right = mid + 1; 

	/*Search for both side for a non empty string*/
	while (true) { 

	/* No non-empty string on both sides */
	if (left < low && right > high) 
		return -1; 

	if (left >= low && arr[left] != "") { 
		mid = left; 
		break; 
	} 

	else if (right <= high && arr[right] != "") { 
		mid = right; 
		break; 
	} 

	left--; 
	right++; 
	} 
} 

/* Normal Binary Search */
if (arr[mid] == x) 
	return mid; 
else if (x.compareTo(arr[mid]) < 0) 
	return binarySearch(arr, low, mid - 1, x); 
else
	return binarySearch(arr, mid + 1, high, x); 
} 

static int sparseSearch(String arr[], String x, int n) { 
return binarySearch(arr, 0, n - 1, x); 
} 

public static void main(String args[]) { 

String arr[] = {"for", "geeks", "", "", "", "", "ide", 
					"practice", "", "", "", "quiz"}; 
String x = "geeks"; 
int n = x.length(); 
int index = sparseSearch(arr, x, n); 
if (index != -1) 
	System.out.println(x+ " found at index "+index); 
else
	System.out.println(x+" not found"); 

} 
} 
