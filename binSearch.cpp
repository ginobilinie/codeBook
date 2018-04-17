#include<iostream>

using namespace std;

#define N 100
int binSearch(int arr[N],int len, int target);

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10,11};
	int loc=binSearch(arr,11,4);
	cout<<"location is "<<loc<<endl;
}

int binSearch(int arr[N],int len, int target)
{
	int left=0,right=len-1;
	int mid;
	int ind=-1;
	while(left<right)
	{
		mid=(left+right)/2;
		if (arr[mid]==target)
		{
			ind=mid;
			break;
		}
		else if (arr[mid]<target)
		{
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	return ind;
}
