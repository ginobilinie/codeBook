class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (!numRows)
            return {};
        vector<int> tmp;
        vector<vector<int>> res;
        
        if (numRows>=1)
        {
            tmp.push_back(1);
            res.push_back(tmp);
            tmp.clear();
        }
        if (numRows>=2)
        {            
            tmp.push_back(1);
            tmp.push_back(1);
            res.push_back(tmp);
            tmp.clear();
        }

        for (int i=2; i<numRows; i++)
        {
            tmp.push_back(1);
            // vector prev = res[i-1];
            for (int j=1; j<i; j++)
            {
                
                int d = res[i-1][j-1]+res[i-1][j];
                tmp.push_back(d);
            }
            tmp.push_back(1);
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};
