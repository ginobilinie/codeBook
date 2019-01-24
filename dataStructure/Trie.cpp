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
        }
        cout<<"haha"<<endl;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
