class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1;
        stack<int> signstack;//use to store the sign
        // signstack.push(sign);
        stack<int> valstack;//use to store the left side value of the sign
        for (int i=0; i<s.length(); i++)
        {
            switch (s[i])
            {
                case '+':
                    sign = 1;
                    break;
                case '-':
                    sign = -1;
                    break;
                case '(':
                    signstack.push(sign);
                    valstack.push(res);//the current value goes to stack
                    res = 0;
                    sign = 1;
                    break;
                case ')':
                    if (!signstack.empty())
                    {
                        int hisval = valstack.top();
                        valstack.pop();
                        res = hisval + signstack.top()*res;
                        signstack.pop();
                    }
                    break;
                case ' ':
                    break;
                default:
                    int currNum = 0;
                    // cout<<s[i]<<" ";
                    while (i<s.length()&&'0'<=s[i]&&s[i]<='9')
                    {
                        currNum = currNum*10 + (s[i] - '0');//this very detail is very important
                        i++;
                    }
                    i--;
                    res += sign*currNum;
                    cout<<res<<" ";
            }
        }
        return res;
    }

};
