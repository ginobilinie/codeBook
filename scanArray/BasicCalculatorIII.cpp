class Solution {
public:
    int calculate(string s) {
        /*
        op记录着上一个operation，我们可以在式子左边假设一个0+...，所以op开场是'+'
        每次遇到s[i]是+-/ or *，我们处理用op去处理右边的元素，到了最后一个元素的时候，我们用当前存留的op去处理就行。也就是n-1个op处理n个item，然后记得去用s[i]去更新op.
        遇到(，go through直到遇到平衡后的)(也就是要记录左右括号数量，要平衡)，然后调用递归算法。
        这种方法，不用stack，不用queue
        */
        int len = s.length();
        int currRes = 0, res = 0, num;
        char op = '+';
        for (int i=0; i<len; i++)
        {
            // if (s[i]==' ')
            //     continue;
            if (s[i]<='9'&&s[i]>='0')
            {
                num = 0;
                while (i<len&&s[i]<='9'&&s[i]>='0')
                {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                i--;
            }
            else if (s[i]=='(')
            {
                int cnt = 0, j = i;
                while (i<len)
                {
                    if (s[i]=='(') cnt++;
                    if (s[i]==')') cnt--;
                    // cout<<cnt<<endl;
                    if (cnt==0)
                        break;
                    i++;
                }
                string ss = s.substr(j+1,i-j-1);
                num = calculate(ss);
            }
            if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||i==len-1)
            {
                switch (op)//op actually records the last operator
                {
                          
                    case '+': currRes += num; break;
                    case '-': currRes -= num; break;
                    case '*': currRes *= num; break;
                    case '/':  currRes /= num;  break;
                }
                if (s[i]=='+'||s[i]=='-'||i==len-1)
                {
                    res += currRes;
                    currRes = 0;
                }
                num = 0;
                op = s[i];
            }
        }
        return res;
    }
};
