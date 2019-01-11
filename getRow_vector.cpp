class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // if (rowIndex==0)
        //     return ;
        vector<int> prev, curr;
        if (rowIndex>=0)
        {
            prev.push_back(1);
            curr = prev;
        }
        if (rowIndex>=1)
        {
            prev.push_back(1);
            curr = prev;
        }
        if (rowIndex<2)
            return curr;
        

        for (int i=2; i<rowIndex+1; i++)
        {
            curr.clear();
            curr.push_back(1);
            for (int j=1; j<i; j++)
            {
                int d = prev[j-1]+prev[j];
                curr.push_back(d);
            }
            curr.push_back(1);
            prev = curr;
        }
        
        return curr;

    }
};
