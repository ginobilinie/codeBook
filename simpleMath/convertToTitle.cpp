class Solution {
public:
    string convertToTitle(int n) {
        int p;
        string res="";
        string dict = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        while(n)
        {
            p = (n-1)%26;
            // cout<<p<<endl;
            res = dict[p] + res;
            n = (n-1)/26;
        }
        return res;
    }
};
