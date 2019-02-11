class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty())
            return "";
        
        string res = "";
        unordered_map<char,vector<char>> mymap;
        string prev = words[0];
        unordered_map<char,int> dict;
        for (char c : prev)
            dict[c] = 0;
        string word;
        for (int i=1; i<words.size(); i++)
        {
            word = words[i];
            for (char c : word)
                dict[c] = 0;
            //compare prev and word
            int p = 0;
            while (p<prev.length()&&p<word.length()&&prev[p]==word[p])
            {
                p++;
            }
            if (p<prev.length()&&p<word.length())
            {
                if (mymap.count(prev[p]))
                    mymap[prev[p]].push_back(word[p]);
                else
                {
                    vector<char> myvec;
                    myvec.push_back(word[p]);
                    mymap[prev[p]] = myvec;  
                }
                    
            }
            prev = word;
        }
        //use the idea of topological sort to make it
        for (auto it : mymap)
        {
            for (char c : it.second)
            dict[c]++;
        }
        
        queue<char> myq;
        for (auto it : dict)
        {
            if (it.second==0)
                myq.push(it.first);
        }
        

        while (!myq.empty())
        {
            char c = myq.front();
            myq.pop();
            res += c;
            for (char x : mymap[c])
            {
                dict[x]--;
                if (dict[x]==0)
                    myq.push(x);
            }
                
        }            
        if (res.length()!=dict.size())
            res = "";
        return res;
    }
};
