class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        // bool* splitVec = new bool(len);
        vector<int> splitVec;
        for (int i=0; i<len; i++)
            splitVec.push_back(0);
        int leftP=0, rightP=0;
     
        
        // memset(splitVec,0,len*sizeof(bool));
        for(int i=0; i<len; i++)
        {
            if (s[i]=='(')
                leftP++;
            else
                rightP++;
            if (rightP>leftP)
            {
                splitVec[i] = 1;
                rightP = 0;
                leftP = 0;
            }

        }
        leftP = 0, rightP = 0;
        for (int i=len-1; i>-1; i--)
        {
            if (s[i]==')')
                rightP++;
            else
                leftP++;
            if (leftP>rightP)
            {
                splitVec[i] = 1;
                rightP = 0;
                leftP = 0;            
            }
        }

        int res = 0, tmp=0;       
        for(int i=0; i<len; i++)
        {
            if (splitVec[i])
            {
                if (res<tmp)
                    res = tmp;
                tmp = 0;
            }
            else
                tmp++;

        }
        res = res>tmp?res: tmp;
    
        
        
//     int res = 0, tmp;       
//         for(int i=0; i<len; i++)
//         {
//             if (s[i]=='(')
//                 leftP++;
//             else
//                 rightP++;
//             if (rightP>leftP)
//             {
//                  tmp = leftP>rightP?rightP:leftP;
//                  if (tmp>res)
//                      res = tmp;
//                  rightP = 0;
//                 leftP = 0;
//             }

//         }
//         tmp = leftP>rightP?rightP:leftP;
//         res = res>tmp?res: tmp;
        
//         leftP=0, rightP=0;
//         int res1 = 0;
//         for (int i=len-1; i>-1; i--)
//         {
//             if (s[i]==')')
//                 rightP++;
//             else
//                 leftP++;
//             if (leftP>rightP)
//             {
//                 tmp = rightP;
//                 if (res1<tmp)
//                     res1 = tmp;
//                 leftP = 0;
//                 rightP = 0;
//             }
//         }
//         tmp = leftP>rightP?rightP:leftP;
//         res1 = res1>tmp?res1:tmp;
        
//         res = res<res1?res:res1;
        
        return res;
    }
};
