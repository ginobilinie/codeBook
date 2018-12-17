class Solution {
public:
    bool isValid(string s) {
        map<char,int> mymap;
        mymap['('] = -1;
        mymap[')'] = 1;
        mymap['{'] = -2;
        mymap['}'] = 2;
        mymap['['] = -3;
        mymap[']'] = 3;
        
        stack<char> mystack;
        int len = s.length();
        
        bool flag = true;
        for (int i=0; i<len; i++)
        {
            if (s[i]=='('||s[i]=='['||s[i]=='{')
                mystack.push(s[i]);
            else
            {
                if (mystack.empty())
                {
                    flag = false;
                    break;
                }
                char top = mystack.top();
                mystack.pop();
                if (mymap[top]+mymap[s[i]]==0)
                    continue;
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (!mystack.empty())
            flag = false;
        return flag;
    }
};
