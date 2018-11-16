#include<iostream>
#include<algorithm>
using namespace std;
#define N 20001
int data[N];
bool cmp(int a, int b)
{
	return a<b;
}
int main()
{
	int n,s;
	cin>>n>>s;
	for (int i=0;i<n;i++)
		scanf("%d",data+i);
	sort(data,data+n,cmp);
	int l=0,r=n-1;
	int res=0;
	while(l<r)
	{
		//fix left index, and make right index 
		for (;data[r]+data[l]>s&&r>l;r--);
		res+=r-l;
		l++;//make the left index right
	}
	cout<<res<<endl;
	return 0;
}