class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        bfs (beginWord, endWord, wordList);
        return res;
    }
    
    void bfs (string beginWord, string endWord, vector<string>& wordList)
    {
        queue<vector<string>> myq;
        int sz = wordList.size();
        vector<int> used(sz,0);
        int depth = 0;
        //myq.push(beginWord);
        depth++;
        bool flag = 0;
        // vector<vector<string>> mat;
        vector<string> vec;
        vec.push_back(beginWord);
        // mat.push_back(vec);
        myq.push(vec);
        while(!myq.empty())
        {
            int qsz = myq.size();
            for (int i=0; i<qsz; i++)
            {
                vector<string> currWordVec = myq.front();
                myq.pop();
                string currWord = currWordVec[currWordVec.size()-1];
                if (currWord==endWord)
                {
                    res.push_back(currWordVec);
                    flag = 1;
                }
                
                for (int j=0; !flag&&j<wordList.size(); j++)
                {
                    if (!used[j]&&canTransform(currWord,wordList[j]))
                    {
                        currWordVec.push_back(currWord);
                        myq.push(currWordVec);   
                        used[j] = 1;
                    }
                }
                
            }
            if (flag)
                break;
            depth++;
        }
    }
    
    bool canTransform(string s1, string s2)
    {
        int cnt = 0;
        for (int i=0; i<s1.length(); i++)
        {
            if (s1[i]!=s2[i])
            {
                cnt++;
                if (cnt>1)
                    return false;
            }
        }
        return true;
    }
};
