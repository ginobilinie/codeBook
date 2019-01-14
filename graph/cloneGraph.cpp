/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    //a dfs solves it
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mymap;
        UndirectedGraphNode *res = dfs(node, mymap);
        return res;
    }
    
    UndirectedGraphNode *dfs (UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>& mymap)
    {
        if (!node)
            return NULL;
        UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
        mymap[node] = newnode;
        vector<UndirectedGraphNode *> newneighbors;
        for (int i=0; i<node->neighbors.size(); i++)
        {
            UndirectedGraphNode * ugnode = node->neighbors[i];
            if (mymap.count(ugnode)==0)
			{
				UndirectedGraphNode * newugnode = dfs(ugnode,mymap);
				newneighbors.push_back(newugnode);
                mymap[ugnode] = newugnode;
			}
			else
			{
				newneighbors.push_back(mymap[ugnode]);
			}
        }
        newnode->neighbors = newneighbors;
        return newnode;
    }
};
