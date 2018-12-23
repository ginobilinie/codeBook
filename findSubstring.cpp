class Solution {
public:
    
    int biSearch(vector<string> &words, string target)
    {
        int sz = words.size();
        int l=0, r=sz-1, mid = (1+r)/2;
        int res = -1;
        while (l<=r)
        {
            mid = (l+r)/2;
            if (words[mid]==target)
            {
                res = mid;
                break;
            }
            else if (target.compare(words[mid])>0)
            {
                l = mid+1;
            }
            else
                r = mid - 1;
        }
        return res;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int sz = words.size();
        vector<int> res;
        // vector<bool> used;
        if (sz==0)
            return res;
        string word = words[0];
        int unitLen = word.length();
        int wordsLen = unitLen*sz;
        int len = s.length();
        if (len<wordsLen)
            return res;
        
        sort(words.begin(),words.end());
        string tmp, ww;
        int ind=-1,j;
        for (int i=0;i<len-wordsLen+1; i++)
        {
            vector<string> dict = words;
            // for (j = 0; j<sz; j++)
                // used[j] = false;
            tmp = s.substr(i,wordsLen);
            //to check if tmp contains the words or not
            for (j=0; j<sz; j++)
            {
                ww = tmp.substr(0+j*unitLen,unitLen);
                ind = biSearch(dict,ww);
                if (ind==-1)
                {
                    break;
                }
                else
                {
                    dict.erase(dict.begin()+ind);
                    // used[ind] = true;
                }        
            }
            if (j==sz)
                res.push_back(i);
        }
        return res;
    }
};
