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
        
        while(!myq.empty())
        {
            if (myq.front()==endWord)
            {
                flag = 1;
                break;
            }
            string word = myq.front();
            myq.pop();
            //transform
            for (int i=0; i<wordList.size(); i++)
            {
                string ww = wordList[i];
                if (!used[i]&&diffNums(word,ww)==1)
                {
                    myq.push(ww);
                    used[i] = 1;
                }
            }
            
            depth++;
        }
        
        if (!flag)
            return 0;
        return depth-1;
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
