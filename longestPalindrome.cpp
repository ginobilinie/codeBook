class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        //we can traverse all the middle point
        int maxLen=0, leftInd=0, rightInd=0;
        for (int i=0;i<len;i++)
        {
        
            int currLen = 1; // for odd case
            int j;
            for(j=1;i-j>=0 && i+j<len;j++)//j index the palindromic around i, we assume odd case
            {
                if (s[i-j]==s[i+j])
                    currLen = currLen+2;
                else
                {
                    break;    
                }                
            }
            if (currLen>maxLen)
            {
                maxLen = currLen;
                leftInd = i-j+1;
                rightInd = i+j-1;
            }
            
            currLen = 0; //for even case
            for (j=0; i-j>=0 && i+1+j<len; j++)
            {
                if(s[i+1+j]==s[i-j])
                {
                    currLen = currLen +2;
                }
                else
                {
                    break; 
                }
            }
            if (currLen>maxLen)
            {
                maxLen = currLen;
                leftInd = i-j+1;
                rightInd = i+1+j-1;
            }
        }
        string subs = s.substr(leftInd,rightInd-leftInd+1);
        return subs;
    }
};
