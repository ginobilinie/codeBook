//sum[n]=min(sum[n-coin[0]],sum[n-coin[1]],sum[n-coin[2]])
#include<iostream>
using namespace std;

Struct coin{
	Int nconin;
	Int lastcoin;
	Int coinV;
};
int main()
{
	Struct coin *sum = new struct coin[totalNum];
	For (int i=0;i<totalValue;i++)
		For (int j=0;j<coinTypeNum;j++)
		{
If (i-coinX[j]>0&&sum[i].ncoin>sum[i-coinX[j]].ncoin+1)
{
	sum[i].ncoin=sum[i-coinX[j]].ncoin+1;
	sum[i].lastcoin=j;
	sum[i].coinV=coinX[j];
}
}
	Delete [] sum;
Return 0;
}
