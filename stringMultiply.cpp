class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        string tt;
        int tmp;
        if (len1<len2)
        {
            tt = num1;
            num1 = num2;
            num2 = tt;
            tmp = len1;
            len1 = len2;
            len2 = tmp;
        }
        
        int currDigit, currVal;
        //currRes stores results for one digits from num2
        //hisRes stores the current history results for all the current used digits from num2
        vector<int> currRes, hisRes;
        for (int i=len2-1; i>-1; i--)
        {
            int currDigit = num2[i]-'0';
            currRes.clear();
            for (int k = i; k<len2-1; k++)
                currRes.push_back(0);
            for (int j=len1-1; j>-1; j--)
            {
                int currVal = num1[j]-'0';
                tmp = currVal * currDigit;
                currRes.push_back(tmp);
            }
            if (hisRes.empty())
            {
                hisRes = currRes;
            }else
            {
                int commonLen = currRes.size()<hisRes.size()?currRes.size():hisRes.size();
                for (int k=0; k<commonLen; k++)
                {
                    hisRes[k] += currRes[k];
                }
                if (currRes.size()>hisRes.size())
                {
                    for (int k= commonLen; k<currRes.size(); k++)
                        hisRes.push_back(currRes[k]);
                } 
            }
        }
        tmp = 0;
        for (int i=0; i<hisRes.size(); i++)
        {
            hisRes[i] += tmp;
            tmp = hisRes[i]/10;
            hisRes[i] %= 10;
        }
        if (tmp>0)
            hisRes.push_back(tmp);
        string res="";
        bool firstDigit = false;
        for (int i=hisRes.size()-1; i>-1; i--)
        {
            if (hisRes[i]!=0)
                firstDigit = true;
            if (firstDigit)
            {
                char cc = hisRes[i]+'0';
                res += cc;                
            }
        }
        if (!firstDigit)
            res = "0";
        return res;
    }
};
