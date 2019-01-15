class Solution {
public:
    struct node
    {
        int val;
        int ind;
        node(int v, int i):val(v),ind(i){}
    };
    static bool cmp(node n1, node n2)
    {
        if (n1.val==n2.val)
            return n1.ind<n2.ind;
        return n1.val<n2.val;
    }
    int candy(vector<int>& ratings) {
        /*
        In my first thought, I think we can first find the min value, and propogate from the min value location to
        the left or right sides. Obviously, this cannot work for long sequence.
        Then I though we can sort this ratings together with their location information. Then we sort from left to right
        we can use map (automatically ranking the key) or use a struct to sort the ratings with its location. Then we can the sorted array from left to right and check if the index's left or right is visted or not, if neighbors are not visited, then we assign 1, otherwise max(leftVal, rightVal) or max(leftVal, rightVal)+1;
        */
        if (ratings.empty())
            return 0;
        int sz = ratings.size();
        vector<struct node> mynodes;
        for (int i=0; i<sz; i++)
        {
            struct node nn(ratings[i],i);
            mynodes.push_back(nn);
        }
        sort(mynodes.begin(),mynodes.end(),cmp);
        // vector<bool> used(sz,0);
        vector<int> candy(sz,0);
        for (int i=0; i<sz; i++)
        {
            int ind = mynodes[i].ind;
            if (!candy[ind])
            { 
                if (ind==0)
                {
                    if (candy[1])
                   
                        candy[0] = ratings[0]==ratings[1]?1:candy[1]+1;
                    else
                        candy[0] = 1;
                }
                else if (ind==sz-1)
                {
                    if (candy[sz-2])
                        candy[sz-1] = ratings[sz-1]==ratings[sz-2]?1:candy[sz-2]+1;
                    else
                        candy[sz-1] = 1;
                }
                else
                {
                    if (!candy[ind-1]&&!candy[ind+1])
                        candy[ind] = 1;
                    else if (candy[ind-1]&&candy[ind+1])
                    {
                        if (ratings[ind]==ratings[ind+1]&&ratings[ind]==ratings[ind-1])
                            candy[ind] = 1;
                        else if (candy[ind-1]>candy[ind+1])
                        {
                            candy[ind] = ratings[ind]==ratings[ind-1]?candy[ind+1]+1:candy[ind-1]+1;
                        }
                        // else if (candy[ind+1]>candy[ind-1])
                        else
                        {
                            candy[ind] = ratings[ind]==ratings[ind+1]?candy[ind-1]+1:candy[ind+1]+1;
                        }
                        // else //candy[ind+1]==candy[ind-1]
                        // {
                        //     candy[ind] = ratings[ind]==ratings[ind+1]?1:((candy[ind-1]>candy[ind+1]?candy[ind-1]:candy[ind+1])+1);
                        // }
                    }
                    else if (candy[ind-1])
                    {
                        candy[ind] = ratings[ind]==ratings[ind-1]?1:candy[ind-1]+1;
                    }
                    else//candy[ind+1]
                    {
                        candy[ind] = ratings[ind]==ratings[ind+1]?1:candy[ind+1]+1;
                    }
                }
                // used[i] = 1;
            }
        }
        int res = 0;
        for (int i=0; i<sz; i++)
            res += candy[i];
        return res;
    }
};
