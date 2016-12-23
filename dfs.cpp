#include<iostream>
#include<set>
#include<string>

using namespace std;

#define N 5
int graph[N][N];
void DFS(int,int);
//bool used[N][N];
int hopCnt=0;
int directX[]={1,-1,0,0};
int directY[]={0,0,1,-1};
string str;
set<string> strSet;

bool checkBoundary(int x, int y)
{
	return x<N&&x>=0&&y<N&&y>=0;
}
//string conInt2Str(int n)
//{
//	string s = std::to_string((_ULonglong)n);
//	return s;
//}
int main()
{
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		{
			cin>>graph[i][j];
		}
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		{
			hopCnt=1;
//			memset(used,0,sizeof(used));
			//string st=conInt2Str(graph[i][j]);
			str=graph[i][j];
			DFS(i,j);
		}
		cout<<strSet.size()<<endl;
	return 0;
}

void DFS(int x, int y)
{
	if (hopCnt==6)//insert to a set 
	{
		if (strSet.count(str)==0)
			strSet.insert(str);
		return;
	}
	int dx,dy;
	for (int i=0;i<4;i++)
	{
		dx=x+directX[i];
		dy=y+directY[i];
		//if (checkBoundary(dx,dy)&&!used[dx][dy])
		if (checkBoundary(dx,dy))
		{
			//str+=conInt2Str(graph[dx][dy]);
			str+=graph[dx][dy];
			//used[dx][dy]=1;
			hopCnt++;
			DFS(dx,dy);
			//trace back is very important here, otherwise, I should not use gloabl hopCnt and global str
			hopCnt--;
			str=str.substr(0,str.length() - 1);
		}
	}
}