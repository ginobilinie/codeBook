class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        /*
        We just need to find the predefined following rule paris
        if the number of pairs doesn't equal to len/2, then fail, otherwise, fine
        The key is to find the maximum number of pairs
        */
        bool flag = 1;
        unordered_map<int, int> mymap;
        for (int i=0; i<A.size(); i++)
        {
            if (mymap.count(A[i]))
                mymap[A[i]]++;
            else
                mymap[A[i]] = 1;
        }
        sort(A.begin(),A.end());
        for (int i=0; i<A.size(); i++)
        {
            if (mymap.count(A[i])==0||mymap[A[i]]==0)
            {
                // cout<<"haha"<<endl;
                continue;
            }
            else if  (A[i]==0)
            {
                // cout<<mymap[0]<<endl;
                if (mymap.count(0)&&mymap[0]%2)
                {
                     // cout<<mymap.count(0)<<" "<<mymap[0]<<endl;
                    flag = 0;
                    mymap[0] = 0;
                    // cout<<"haha0"<<endl;
                    break;
                }
            }
            else if (A[i]%2)
            {
                if (mymap.count(2*A[i])&&mymap[A[i]*2])
                    mymap[2*A[i]]--;
                else
                {
                    flag = 0;
                    // cout<<"haha1"<<endl;

                    break;
                }
            }
            else //even
            {
                if (mymap.count(2*A[i])&&mymap[A[i]*2])
                    mymap[2*A[i]]--;
                else if (mymap.count(A[i]/2)&&mymap[A[i]/2])
                    mymap[A[i]/2]--;
                else
                {
                    flag = 0;
                    // cout<<"haha2"<<A[i]<<endl;

                    break;
                }
            }
            if (mymap[A[i]]>0&&A[i])
                mymap[A[i]]--;
        }
        return flag;
    }
};
