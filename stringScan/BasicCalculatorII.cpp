class Solution {
public:
    int calculate(string s) {
        /*once again, we use two stack, sign stack and leftval stack
        when we encounter + or -, we encounter sign and leftvalue into stacks
        when we encounter * or /, we just conduct the operation
        */
        int len = s.length();
        int res = 0;
        char sign = '#';
        queue<int> signstack;
        signstack.push(1);
        queue<int> valstack;
        for (int i=0; i<len; i++)
        {
            switch (s[i])
            {
                case '+':
                    sign = '+';
                    signstack.push(1);
                    valstack.push(res);
                    res = 0;
                    sign = '#';
                    break;
                case '-':
                    sign = '-';
                    signstack.push(-1);
                    valstack.push(res);
                    res = 0;
                    sign = '#';
                    break;
                case ' ':
                    break;
                case '*':
                    sign = '*';
                    break;
                case '/':
                    sign = '/';
                    break;
                default:
                    int currNum = 0;
                    while (i<len&&s[i]>='0'&&s[i]<='9')
                    {
                        currNum = currNum*10 + (s[i]-'0');
                        i++;
                    }
                    i--;
                    if (sign == '#'||sign =='+'||sign=='-')
                        res = currNum;
                    else if (sign=='*')
                    {
                        res = res*currNum;
                    }
                    else
                    {
                        res = res/currNum;
                    }
            }
        }
        valstack.push(res);
        // valstack.push(res);
        if (signstack.empty())
            return res;
        res = 0;
        while (!signstack.empty())
        {
            sign = signstack.front();
            signstack.pop();
            res = res + sign*valstack.front();
            valstack.pop();
        }
        return res;
    }
};
