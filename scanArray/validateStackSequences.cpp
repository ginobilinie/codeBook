class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (popped.empty()&&pushed.empty())
            return 1;
        if (popped.size()!=pushed.size())
            return 0;
        stack<int> s;
        //initialization
        int popInd = 0, pushInd = 0;

        for (int i=0; i<pushed.size(); i++)
        {
            s.push(pushed[i]);
            pushInd++;
            if (pushed[i]==popped[0])
                break;
        }
        while (!s.empty())
        {
            if (s.top()==popped[popInd])
            {
                s.pop();
                popInd++;
            }
            else
            {
                if (pushInd>=pushed.size())
                    return false;
                s.push(pushed[pushInd]);
                pushInd++;
            }
            if (s.empty()&&pushInd<pushed.size())
            {
                 for (int i=pushInd; i<pushed.size(); i++)
                {
                    s.push(pushed[i]);
                    pushInd++;
                    if (pushed[i]==popped[popInd])
                        break;
                }
            }
        }
        return 1;
    }
};
