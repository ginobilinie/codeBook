#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define N 2001

//string strs[N];
char strs[N][10];
int n;//# of strings
struct Edge{
int start,end;
int dist;
};//as we have to sort the edges, so we mainly store them in edge form
struct Edge edges[N*N/2];
int edgeInd=0;
//to judge if there is any loop, we have to use unionSet to fulfill it. 
//We can check the nodes of a chosen edge if the two nodes belong to the same group or not
int parent[N];
void makeSet();
int findSet(int);
void unionSet(int,int);
int computeDist(string s, string t);
int computeDist(int s, int t);

int Kruskal();
bool cmp(Edge e1, Edge e2)
{
	return e1.dist<e2.dist;
}
//Actually, the problem is described in a complicated way. 
//The essence of it is just to generate a short distance coverage between the given strings
//and the distance is defined as position difference between two strings
//And we'd better use Prim to solve this problem, while I've already written Prim, so I utilized Kruskal.
//I donot like to implement adjacent table, so I directly use map 


int main()
{
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
		{
			//cin>>strs[i];
			scanf("%s",strs[i]);
		}
		edgeInd=0;
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
			{
				edges[edgeInd].start=i;
				edges[edgeInd].end=j;
				edges[edgeInd++].dist=computeDist(i,j);
			}
		int res=Kruskal();
		printf("The highest possible quality is 1/%d.\n",res);
	}
	return 0;
}

int computeDist(string s, string t)
{
	int res=0;
	for (int i=0;i<7;i++)
		if (s[i]!=t[i])
			res++;
	return res;
}

int computeDist(int s, int t)
{
	int res=0;
	for (int i=0;i<7;i++)
		if (strs[s][i]!=strs[t][i])
			res++;
	return res;
}

void makeSet()
{
	for (int i=0;i<n;i++)
		parent[i]=i;
}
//find the root of x
int findSet(int x)
{
	if (x==parent[x])
		return x;
	else
		return parent[x]=findSet(parent[x]);
}
void unionSet(int x, int y)
{
	parent[y]=x;
}
int Kruskal()
{
	makeSet();
	//sort the edges according to the distance
	sort(edges,edges+edgeInd,cmp);

	int ind=0;
	int res=0;
	int chosenCnt=0;
	while(ind<edgeInd)//
	{
		int s=edges[ind].start,t=edges[ind].end;
		int rootS=findSet(s);
		int rootT=findSet(t);
		if (rootS!=rootT)//no loop, we can use this edge
		{
			res+=edges[ind].dist;
			unionSet(rootS,rootT);
			chosenCnt++;
		}
		if (chosenCnt==n-1)
		{
			break;//enough
		}
		ind++;
	}
	return res;
}