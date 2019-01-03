class Solution {
public:
    string res="";
    //bool used[9];
    //string dict = "0123456789";

    vector<char> dict;
    string getPermutation(int n, int k) {
        for (int i=1; i<n+1; i++)
            dict.push_back(i+'0');
        int currLayer = n;
        string res = "";
        while(currLayer)
        {
            int f = factorial(currLayer-1);
            int ind = ceil(1.0*k/f);
            if (ind>0)
            {
                res = res + dict[ind-1];
                dict.erase(dict.begin()+ind-1);  
            }
            else
            {
                res = res + dict[ind];
                dict.erase(dict.begin()+ind);
            }
            if (k>f && ind>0)
                k = k - (ind-1)*f;
            currLayer--;
        }

        return res;
    }
    
    int factorial(int n)
    {
        if(n<=1)
            return 1;
        else
            return n*factorial(n-1);
    }
 
};
