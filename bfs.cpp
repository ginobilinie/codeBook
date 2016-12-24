#include<iostream>
#include<queue>
using namespace std;
#define N 5
struct Direction{
int x;
int y;
}ds[4]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

struct Node{
int x,y;//current position
int preX,preY;//previous point on path
int value;
};

Node maze[N][N];
bool used[N][N];
void printPath(int,int);
void BFS();
bool checkBoundary(int x,int y)
{
	return x>=0&&y>=0&&x<N&&y<N;
}
int main()
{
	//ds[0].x=-1,ds[0].y=0;
	//ds[1].x=1,ds[1].y=0;
	//ds[2].x=0,ds[2].y=-1;
	//ds[3].x=0,ds[3].y=1;
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		{
			cin>>maze[i][j].value;
			maze[i][j].x=i,maze[i][j].y=j;//the stored (x,y) is same with the real coordinator, which is important for this problem
		}
	BFS();
	return 0;
}

void BFS()
{
	memset(used,0,sizeof(used));//false initialization
	Node head;
	int dx,dy;
	queue<Node> q;
	q.push(maze[0][0]);//push the start point into the queue
	while(!q.empty())
	{
		head=q.front();
		q.pop(); //queue operation is really joking...ask two steps to get value and pop
		for (int i=0;i<4;i++)//tranverse along 4 directions
		{
			dx=head.x+ds[i].x,dy=head.y+ds[i].y;
			if (!checkBoundary(dx,dy))//outside maze
				continue;
			if (!maze[dx][dy].value&&!used[dx][dy])//if not wall and not visited, visit it
			{
				maze[dx][dy].preX=head.x,maze[dx][dy].preY=head.y;
				used[dx][dy]=1;//(dx,dy)visisted
				q.push(maze[dx][dy]);//note, dx,dy represents the location of the points
			}
			if ((dx==N-1)&&(dy==N-1))//touch end
			{
				printPath(dx,dy);
				return;
			}
		}

	}
}

//trace backt the path
void printPath(int x,int y)
{
	if (x==0&&y==0)//touch the start point
	{	
		cout<<"("<<x<<", "<<y<<")"<<endl;
		return;
	}
	printPath(maze[x][y].preX,maze[x][y].preY);
	cout<<"("<<x<<", "<<y<<")"<<endl;
	return;
}
