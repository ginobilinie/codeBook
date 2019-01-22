class Solution {
public:
    int minDeletionSize(vector<string>& A) {
    /*
        we scan the from left to right across a word, if the current char is seriously ordered in the array, then we donot 
        need to process the later chars; if the current char is ordred but not seriouly ordered, then we need to consider later chars but we donot need to remove the current chars; if the current char is not ordered, then we need to remove the current char, and go to next char.
    */
        if (A.empty())
            return 0;
        int res = 0;
        int wordLen = A[0].length();
        int vecSZ = A.size();
        vector<int> ordered(vecSZ,0);
        int i,j;
        
        for (i=0; i<wordLen; i++)
        {
            //string ss = "";
            //ss += A[0][i];
            int state = 0;//0: <, 1: =, 2:>
            vector<int> tmp;
            for (j=1; j<A.size(); j++)
            {
                //ss += A[j][i];
                if (ordered[j])
                    continue;
                string prevStr = A[j-1];
                string currStr = A[j];
                if (prevStr[i]>currStr[i])
                {
                    state = 2;
                    break;
                }
                else if (prevStr[i]==currStr[i])
                {
                    state = 1;
                }
                else//prev<curr
                {
                    // if (state==1)
                    tmp.push_back(j);
                    continue;
                }
            }
            //cout<<ss<<endl;
            if (state==0)
            {
                return res;
            }
            else if (state==1)
            {
                for (int k = 0; k<tmp.size(); k++)
                {
                    ordered[tmp[k]] = 1;
                }
                // continue;
            }
            else //state==2
            {
                //cout<<" "<<i;
                res++;
            }
        }
        return res;
    }
};
