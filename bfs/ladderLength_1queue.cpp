class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = bfs(beginWord, endWord, wordList);
        return res;
    }
    
    int bfs(string beginWord, string endWord, vector<string>& wordList)
    {
        queue<string> myq;
        myq.push(beginWord);
        int depth = 1;
        bool flag = 0;
        vector<bool> used(wordList.size(),0);
        for (int i=0; i<wordList.size(); i++)
            if (beginWord==wordList[i])
                used[i] = 1;
        
        while(!myq.empty())
        {
            //finish scaning all the nodes in this level (the current queue information)
            int sz = myq.size();
            for (int k=0; k<sz; k++)
            {
                if (myq.front()==endWord)
                {
                    flag = 1;
                    break;
                }
                string word = myq.front();
                myq.pop();
                for (int i=0; i<wordList.size(); i++)
                {
                    string ww = wordList[i];
                    if (!used[i]&&canTransform(word,ww))
                    {
                        myq.push(ww);
                        used[i] = 1;
                    }
                }
            }
           
            if (flag)
                break;
            depth++;
        }
        
        if (!flag)
            return 0;
        return depth;
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
