#include<iostream>
#include<string>
using namespace std;
#define N 1000
int numStrs=0;//record number of strings
string strs[N];
struct node{
	char value;
	int pLeft;//index to left child
	int pRight;//index to right child
}tree[N];//use node array to simulate real binary tree
void buildTree();
void addNode(int nodeInd, char val);
void printTree(int root);
int rootNode=0;
int currInd=0;
int main()
{
	string line;
	while(cin>>line)
	{
		if (line=="*"||line=="$")
		{
			//do the job
			buildTree();
			printTree(rootNode);
			cout<<endl;
			numStrs=0;
			rootNode=0;
			currInd=0;
		}
		else
		{
			strs[numStrs++]=line;
		}
		if (line=="$")
			break;
	}
	return 0;
}

void buildTree()
{
	memset(tree,0,sizeof(tree));
	for (int i=numStrs-1;i>-1;i--)
	{
		for (int j=0;j<strs[i].length();j++)
		{
			char val=strs[i][j];
			addNode(rootNode,val);//join from the root, actually, we didn't make full use of it.
		}
	}
}

void addNode(int nodeInd, char val)
{
	if (tree[nodeInd].value==0)//havent' been assigned value
		{
			tree[nodeInd].value=val;
			return;
		}else if(tree[nodeInd].value<val)//should go to right
		{
			if(tree[nodeInd].pRight==0)//right is empty
				tree[nodeInd].pRight=currInd++;//if we use real pointer, we donot need this step
			addNode(tree[nodeInd].pRight,val);
		}
		else //go to left
		{
			if (tree[nodeInd].pLeft==0)//left is empty
				tree[nodeInd].pLeft=currInd++;//if we use real pointer, we donot need this step
			addNode(tree[nodeInd].pLeft,val);
		}
}

void printTree(int root)
{
	cout<<tree[root].value;
	if (tree[root].pLeft!=0)
		printTree(tree[root].pLeft);
	if (tree[root].pRight!=0)
		printTree(tree[root].pRight);
}