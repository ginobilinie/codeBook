class Solution {
public:
    set<vector<int>> myset;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int len = candidates.size();
        for (int i=0; i<len; i++)
        {
            vector<int> currCombination;
            if (candidates[i]>target)
                break;
            currCombination.push_back(candidates[i]);
            dfs(candidates, target, i,currCombination, candidates[i]);
        }
        vector<vector<int>> myvec(myset.begin(),myset.end());
        return myvec;
    }
    
    void dfs(vector<int>& candidates, int target, int currInd, vector<int>& currCombination, int currSum)
    {
        if (currSum==target)
        {
            sort(currCombination.begin(),currCombination.end());
            myset.insert(currCombination);
            return;
        }
        int len = candidates.size();
        for (int i=currInd+1; i<len; i++)
        {
            if (currSum+candidates[i]<=target)
            {
                currSum +=candidates[i];
                currCombination.push_back(candidates[i]);
                dfs(candidates, target,i, currCombination, currSum);
                currSum -=candidates[i];
                currCombination.erase(currCombination.begin()+currCombination.size()-1); 
            }
            else
                break;
        }
    }
};
