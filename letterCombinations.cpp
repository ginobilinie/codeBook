class Solution {
public:
    vector<string> res;
    string words[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string currStr = "";
    vector<string> letterCombinations(string digits) {
        // int[] numbers = {2,3,4,5,6,7,8,9};
        int len = digits.length();
        
        int currInd = 0;
        if(digits=="")
            return res;
        dfs(digits,currInd);
        return res;
    }
    
    void dfs(string str, int currInd)
    {
        if (currInd==str.length())
        {
            res.push_back(currStr);
            return;
        }

        int ind = str[currInd]-'2';
        string word = words[ind];
        for (int i=0; i<word.length(); i++)
        {
            string tmp = currStr;
            currStr = currStr + word[i];
            currInd++;
            dfs(str, currInd);
            currInd--;
            currStr = tmp;
        }
    }
    
};
