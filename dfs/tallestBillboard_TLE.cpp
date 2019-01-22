class Solution {
public:
   int tallestBillboard(vector<int>& rods, int i = 0, int s1 = 0, int s2 = 0) {
        if (i >= rods.size()) return s1 == s2 ? s1 : 0;
            return max({ tallestBillboard(rods, i + 1, s1, s2), 
                           tallestBillboard(rods, i + 1, s1 + rods[i], s2), 
                           tallestBillboard(rods, i + 1, s1, s2 + rods[i]) });
    }
};
