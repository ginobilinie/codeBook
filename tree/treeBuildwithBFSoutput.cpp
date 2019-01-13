#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;


//This is a hard problem, to build a tree according to post-order traverse is easy, but to output from down-to-up, right-to-left is hard.
//thus, we can use BFS to visit the tree, and then output the order reversely
#define N 10001
struct node
{
	int pLeft;
	int pRight;
	char value;
}tree[N];

int nodeInd=0;

void buildTree();
void printTreeWithBFS();

string line;
int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		cin>>line;
		memset(tree,-1,sizeof(tree));
		nodeInd=0;
		buildTree();
		printTreeWithBFS();
	}
	return 0;
}

void buildTree()
{
	stack<int> s;
	for (int i=0;i<line.length();i++)//note, use the node index as flag make the problem much easier
	{
		if (line[i]<='z'&&line[i]>='a')
		{
			tree[nodeInd].value=line[i];//first specify the node value
			s.push(nodeInd++);
		}
		else if (line[i]<='Z'&&line[i]>='A')//pop the first two nodes
		{
			int ind1=s.top();
			s.pop();
			int ind2=s.top();
			s.pop();
			tree[nodeInd].value=line[i];
			tree[nodeInd].pLeft=ind2;
			tree[nodeInd].pRight=ind1;
			s.push(nodeInd++);
		}
	}
}

void printTreeWithBFS()
{
	//the root node is the last one
	string outLine;
	queue<int> q;
	q.push(nodeInd-1);
	while (!q.empty())
	{
		int currInd=q.front();
		outLine.push_back(tree[currInd].value);
		q.pop();
		if (tree[currInd].pLeft!=-1)
			q.push(tree[currInd].pLeft);
		if (tree[currInd].pRight!=-1)
			q.push(tree[currInd].pRight);
	}
	reverse(outLine.begin(),outLine.end());//good function, haha
	cout<<outLine<<endl;
}
