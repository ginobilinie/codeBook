class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        /*
        get sum, and check from sum/2 to 1
        */
        if (rods.empty())
            return 0;
        int sum = 0;
        for (int i=0; i<rods.size(); i++)
            sum += rods[i];
        sum = sum/2+1;
        int res = 0;
        while (sum--)
        {
            cout<<sum<<endl;
            vector<bool> used(rods.size(),0);
            bool flag1 = 0, flag2=0;
            dfs(rods, sum,0, used, flag1);
            if (!flag1)
                continue;
            cout<<"haha0: ";
            for (int i=0; i<rods.size(); i++)
                cout<<used[i]<<" ";
            cout<<" haha1"<<endl;
            dfs(rods,sum,0,used,flag2);
            cout<<"haha2: ";
            for (int i=0; i<rods.size(); i++)
                cout<<used[i]<<" ";
            cout<<" haha3"<<endl;
            if (flag2)
            {
                res = sum;
                break;
            }
        }
        return res;
    }
    
    void dfs(vector<int>& rods, int target, int currSum, vector<bool>& used, bool& flag)
    {
        if (currSum==target)
        {
            flag = 1;
            return;
        }
        for (int i=0; i<rods.size(); i++)
        {
            if (!used[i])
            {
                if (currSum+rods[i]>target)
                    continue;
                used[i] = 1;
                dfs(rods,target,currSum+rods[i],used,flag);
                if (flag)
                    return;
                used[i] = 0;
            }
        }
    }
};
