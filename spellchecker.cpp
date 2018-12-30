class Solution {
public:
    // bool cmp(string& s1, string& s2)
    // {
    //     if ()
    // }
    
    char dict[5]={'a', 'e', 'i', 'o', 'u'};
    string str2lowercase(string s)
    {
        if (s=="")
            return s;
        string res="";
        for (int i=0; i<s.length(); i++)
        {
            if (s[i]<='Z'&&s[i]>='A')
                res[i] = s[i]+32;
        }
        return res;
    }        

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int queryLen = queries.size();
        int wordlistLen = wordlist.size();
        
        vector<string> resVec;
        vector<string> res;
        string tmp="";
        // vector<string> wordlist_lowercase;
        map<string, int> wordlistMap;
        map<string, int> lowercasewordlistMap;
        for (int i=0; i<wordlistLen; i++)
        {
            tmp = wordlist[i];
            if (wordlistMap.count(tmp)==0)
            {
                wordlistMap[tmp] = i;
            }
            // tmp = wordlist[i];
            tmp = str2lowercase(tmp);
            if (lowercasewordlistMap.count(tmp)==0)
            {
                lowercasewordlistMap[tmp] = i;
            }
        }
        
        // sort(wordlist.begin(),wordlist.end());
        for (int i=0; i<queryLen; i++)
        {
            string query = queries[i];
            string lowercasequery = str2lowercase(query);
            int fff = 0; //0-no match, 1-exact match, 2-not exact match
            if (wordlistMap.count(query)>0)//exact-match
                res.push_back(query);
            else if (lowercasewordlistMap.count(lowercasequery)>0)//capital case
            {
                int ind = lowercasewordlistMap[lowercasequery];
                res.push_back(wordlist[ind]);
            }
            else
            {
                tmp = lowercasequery;
                bool flag = false;
                for (int k=0; !flag&&k<5; k++)
                {
                    char c = dict[k];
                    for (int i=0; !flag&&i<lowercasequery.length(); i++)
                    {
                        if (lowercasequery[i]==c)
                        {
                            for (int j=0; j<5; j++)
                            {
                                tmp[i] = dict[j];
                                if (lowercasewordlistMap.count(tmp)>0)
                                {
                                    int ind = lowercasewordlistMap[lowercasequery];
                                    res.push_back(wordlist[ind]);  
                                    flag = true;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (!flag)
                    res.push_back("");
            }
    
        }
        return res;
    }
};
