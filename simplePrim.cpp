#include<iostream>
using namespace std;
#define N 501
#define INF 0x3f3f3f3f

int graph[N][N];
int prim(int);
int lowCost[N];//to record distance between unchosen points to chosen points
bool used[N];//to indicate whether this point is chosen or not
int n;//# of villages

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		cin>>n;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				cin>>graph[i][j];
			}
		int res=prim(0);
		cout<<res<<endl;
		//if (cases!=0)
		//	cout<<endl;//extra empty line
	}
	return 0;

}

int prim(int seed)
{
	memset(used,0,sizeof(used));
	memset(lowCost,-1,sizeof(lowCost));
	used[seed]=1;
	//we initialize the distance between seed and unchosen points
	for (int i=0;i<n;i++)
		if (!used[i])
			lowCost[i]=graph[seed][i];
	for (int i=0;i<n-1;i++)//we have to choose the next n-1 points sequentialy
	{
		int temp=INF;
		int currP=-1;
		for (int j=0;j<n;j++)
			if (!used[j]&&lowCost[j]<temp)//choose a neareast point
			{
				temp=lowCost[j];
				currP=j;
			}
		if (currP!=-1)
			used[currP]=-1;//update chosen sets
		//now we have to update the lowCost array, this is very important to make the prim algorithm as efficient as possible
		for (int j=0;j<n;j++)
			if(!used[j]&&graph[currP][j]<lowCost[j])
				lowCost[j]=graph[currP][j];
	}

	//now output the longest road, all the distances for chosen roads are in the lowCost
	int tt=0;
	for (int i=0;i<n;i++)
		if (tt<lowCost[i])
			tt=lowCost[i];

	return tt;
}
