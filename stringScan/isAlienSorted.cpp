class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.empty()||order.length()==0)
            return 1;
        int sz = words.size();
        bool flag = 1;
        unordered_map<char,int> mymap;
        for (int i=0; i<order.length(); i++)
        {
            mymap[order[i]] = i;
        }
        for (int i=1; i<sz; i++)
        {
            //compare word0 vs. word1
            flag = compare(words[i-1], words[i], mymap);
            if (!flag)
                break;
        }
        // cout<<"haha"<<flag<<endl;
        return flag;
    }
    bool compare(string word1, string word2, unordered_map<char,int>& mymap)
    {
        int p = 0, len1 = word1.length(), len2 = word2.length();
        int flag = -1;
        while (p<len1&&p<len2)
        {
            // cout<<mymap[word1[p]]<<" "<<mymap[word2[p]]<<endl;
            if (mymap[word1[p]]<mymap[word2[p]])
            {
                flag = 1;
                break;
            }
            else if (mymap[word1[p]]>mymap[word2[p]])
            {
                flag = 0;
                break;
            }
            p++;
                // break;
        }
        if (flag==-1)
            if (len1<=len2)
                flag = 1;
            else
                flag = 0;
        // cout<<flag<<endl;
        return flag;
    }
};
