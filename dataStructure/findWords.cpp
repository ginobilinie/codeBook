class Solution {
public:
    class Trie {
    public:
        /** Initialize your data structure here. */
        Trie() {
            root = new TrieNode(); 
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            TrieNode *p = root;
            for (int i=0; i<word.length(); i++)
            {
                char c = word[i];
                int ind = c - 'a';
                if (p->child[ind]==NULL)
                    p->child[ind] = new TrieNode();
                p = p->child[ind];
            }
            p->isWord = 1;

        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            TrieNode* p = root;
            for (int i=0; i<word.length(); i++)
            {
                char c = word[i];
                int ind = c - 'a';
                if (p->child[ind]==NULL)
                    return false;
                p = p->child[ind];
            }
            // cout<<"haha"<<endl;
            return p->isWord;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            TrieNode *p = root;
            for (int i=0; i<prefix.length(); i++)
            {
                char c = prefix[i];
                int ind = c - 'a';
                if (p->child[ind]==NULL)
                    return false;
                p = p->child[ind];
            }
            return true;
        }

    private:
        struct TrieNode
        {
            bool isWord;
            TrieNode* child[26];
            TrieNode():isWord(false)
            {
                for (auto &ch : child)
                    ch = NULL;
            }
        };
        TrieNode *root;
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()||words.empty())
            return {};
        int rows = board.size();
        int cols = board[0].size();
        // unordered_set<string> myset;
        Trie* mytrie = new Trie(); 
        for (auto word : words)
            mytrie->insert(word);
        unordered_set<string> res;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
            {
                string currStr = "";
                currStr += board[i][j];
               
                vector<vector<bool>> used(rows,vector<bool>(cols,0));
                used[i][j] = 1;
                if (mytrie->startsWith(currStr))
                    dfs(board,mytrie,used,i,j,currStr,res);                
            }
        vector vec(res.begin(),res.end());
        return vec;
    }
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    void dfs(vector<vector<char>>& board, Trie* mytrie, vector<vector<bool>> &used, int x, int y, string & currStr, unordered_set<string>& res)
    {
        if (mytrie->search(currStr))
        {
            res.insert(currStr);
        }
        for (int i=0; i<4; i++)
        {
            int px = x+ dx[i];
            int py = y + dy[i];
            if (px>=board.size()||px<0||py>=board[0].size()||py<0||used[px][py])
                continue;
            string tmp = currStr + board[px][py];
            
            if (mytrie->startsWith(tmp))
            {
                used[px][py] = 1;
                dfs(board, mytrie, used, px,py, tmp, res);
                used[px][py] = 0;
            }
                
        }
    }
};
