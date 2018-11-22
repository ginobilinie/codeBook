class Solution {
public:
 int myAtoi(string str) {
        int len = str.length();
        long long res = 0;
        bool flag = false;
        int sign = 1;
        for (int i=0;i<len;i++)
        {
            if (str[i]==' ')
                if (flag)
                    break;
                else
                    continue;
            else if (str[i]<='9'&&str[i]>='0')
            {
                flag = true;
                res = res*10 + str[i]-'0';
				if (res>INT_MAX)
				{
					if (sign==1)
						res = INT_MAX;
					else
						res = INT_MIN;
					break;
				}
                    
            }
            else if (str[i]=='+')
            {
                if (!flag)
                {
                    sign = 1;
                    flag = true;
                }
                else
                    break;
            }
            else if (str[i]=='-')
            {
                if (!flag)
                {
                     sign = -1;   
                     flag = true;
                }
                else
                    break;
            }
            else
            {
                break;
            }
        }
        res = res * sign;
  /*      if (res>INT_MAX)
            res = INT_MAX;
        else if (res<INT_MIN)
            res = INT_MIN;
			*/
        return res;
    }
};
