#include<iostream>
using namespace std;
#define N 50001
int parent[N];
int myrank[N];

void makeSet(int);
int findSet(int);
void unionSet(int,int);
int main()
{
	int cases=0;
	int m,n;
	int x,y;
	while((cin>>n>>m)&&m&&n)
	{
		makeSet(n);
		for (int i=0;i<m;i++)
		{
			cin>>x>>y;
			unionSet(x,y);
		}
		int cnt=0;
		for (int i=1;i<n+1;i++)
		{
			int ri=findSet(i);
			if (ri==i)
				cnt++;
		}
		cases++;
		cout<<"Case "<<cases<<": "<<cnt<<endl;

	}
	return 0;
}

void makeSet(int n)
{
	for (int i=1;i<n+1;i++)
	{
		parent[i]=i;
		myrank[i]=1;
	}
}

//find the root of this id can track back to
int findSet(int id)
{
	if (id==parent[id])
		return id;
	else 
		return parent[id]=findSet(parent[id]);
}

//union set
void unionSet(int x, int y)
{
	int rx=findSet(x);
	int ry=findSet(y);
	if ((myrank[rx]<myrank[ry]))
	{
		parent[rx]=parent[ry];
		myrank[ry]+=myrank[rx];
	}else
	{
		parent[ry]=parent[rx];
		myrank[rx]+=myrank[ry];
	}
}
