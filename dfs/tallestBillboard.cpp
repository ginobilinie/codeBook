class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        /*
        get sum, and check from sum/2 to 1
        */
        if (rods.empty())
            return 0;
        int sum = 0;
        for (int i=0; i<rods.size(); i++)
            sum += sum[i];
        sum = sum/2+1;
        
        while (sum--)
        {
            vector<bool> used(rods.size(),0);
            w
        }
    }
};
