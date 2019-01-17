class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        string str;
        int c = 0;
        for (int i=0; i<tokens.size(); i++)
        {
            str = tokens[i];
            if (str=="+"||str=="-"||str=="*"||str=="/")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                // int c;
                if (str=="+")
                    c = b+a;
                else if (str=="-")
                    c = b-a;
                else if (str=="*")
                    c = b*a;
                else
                    c = b/a;
                s.push(c);
            }
            else
            {
                s.push(stoi(str));        
            }
        }
        c = s.top();
        return c;
    }
    
};
