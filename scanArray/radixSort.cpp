#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 

int getMax(vector<int>& arr, int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int n, int exp) 
{ 
    vector<int> output(n); // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) //this coding is very technical: 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
//by dong nie
void countSort(vector<int>& arr, int n, int exp) 
{ 
    vector<int> output(n); // output array 
    int i;
	unordered_map<int,vector<int>> mymap;
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
	{
		int digit = (arr[i]/exp)%10;
        if (mymap.count(digit))
		{
			mymap[digit].push_back(arr[i]);
		}
		else
		{
			vector<int> vec;
			vec.push_back(arr[i]);
			mymap[digit] = vec;
		}
	}
  
  
    // Build the output array 
	int ind = 0;
	arr.clear();
    for (i = 0; i<10; i++) 
    { 
		if (mymap.count(i))
		{
			vector<int> tmp = mymap[i];
			for (int j=0; j<tmp.size(); j++)
			{
				arr.push_back(tmp[j]);
			}
		}

    } 
  
} 


// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixsort(vector<int>& arr, int n) 
{ 
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 
  
// A utility function to print an array 
void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	vector<int> nums(8,0);
	nums[0] = 170;
	nums[1] = 45;
	nums[2] = 75;
	nums[3] = 90;
	nums[4] = 802;
	nums[5] = 24;
	nums[6] = 2;
	nums[7] = 66;
    int n = sizeof(arr)/sizeof(arr[0]); 
    //radixsort(arr, n); 
	radixsort(nums, n); 
    print(arr, n); 
    return 0; 
} 
