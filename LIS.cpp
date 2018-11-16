#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std; 
#define N 40001
int dp[N];
int n;

// int p = lower_bound(dp, dp+cnt+1, tmp) - dp;

int main()
{
     int cases;
     //freopen("input.txt","r",stdin);
     scanf("%d",&cases);
     while(cases--) {
       int p,n,cnt=0;
	   scanf("%d",&p);
	   memset(dp,0,sizeof(dp));
	   for (int i=0;i<p;i++)
	   {
		   scanf("%d",&n);
		   if (cnt==0||n>dp[cnt])
		   {
			   dp[++cnt]=n;
		   }
		   else//if the current data is smaller than the current end element's value of dp
		   {
			   //we have to find the correct position for p
			   int loc = lower_bound(dp, dp+cnt+1, n) - dp;
			   //update that location's value of dp
			   dp[loc]=n;
		   }
	   }
	   printf("%d\n",cnt);
     }    
     return 0;
}