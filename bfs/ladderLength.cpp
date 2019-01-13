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
        int depth = 0;
        bool flag = 0;
        vector<bool> used(wordList.size(),0);
        queue<int> levelq;
        levelq.push(1);
        for (int i=0; i<wordList.size(); i++)
            if (beginWord==wordList[i])
                used[i] = 1;
        
        while(!myq.empty())
        {
            if (myq.front()==endWord)
            {
                flag = 1;
                depth = levelq.front();
               //depth++;
                break;
            }
            string word = myq.front();
            myq.pop();
            int level = levelq.front();
            levelq.pop();
            //transform
            for (int i=0; i<wordList.size(); i++)
            {
                string ww = wordList[i];
                if (!used[i]&&diffNums(word,ww)==1)
                {
                    myq.push(ww);
                    levelq.push(level+1);
                    used[i] = 1;
                }
            }
            
            depth = level;
        }
        
        if (!flag)
            return 0;
        return depth;
    }
    int diffNums(string s1, string s2)
    {
        int cnt = 0;
        for (int i=0; i<s1.length(); i++)
        {
            if (s1[i]!=s2[i])
                cnt++;
        }
        return cnt;
    }
};
