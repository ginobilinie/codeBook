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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        queue<UndirectedGraphNode *> myq;
        myq.push(node);
        UndirectedGraphNode *mynewnode = NULL;
        while(!myq.empty())
        {
            int qsz = myq.size();
            for (int i=0; i<qsz; i++)
            {
                UndirectedGraphNode * currNode = myq.front();
                myq.pop();
                UndirectedGraphNode * newNode, *newNeighbor;
                if (mymap.count(currNode))
                    newNode = mymap[currNode];
                else
                {
                    newNode = new UndirectedGraphNode(currNode->label);
                    mymap[currNode] = newNode;                    
                }
                if (!mynewnode) mynewnode = newNode;             
                for (UndirectedGraphNode * neighbor : currNode->neighbors)
                {
                    if (mymap.count(neighbor))
                    {
                        newNode->neighbors.push_back(mymap[neighbor]);
                    }                    
                    else
                    {
                        newNeighbor = new UndirectedGraphNode(neighbor->label);
                        newNode->neighbors.push_back(newNeighbor);
                        mymap[neighbor] = newNeighbor;
                        myq.push(neighbor);// if it has been copied, wedonot need to visit it again.
                    }
                }
            }
        }
        return mynewnode;      
    }
private:
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mymap;
};
