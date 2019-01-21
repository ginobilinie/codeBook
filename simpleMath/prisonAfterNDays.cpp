class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        /*there must be a circle, since there are totally 6 bits changes (left and right are both 0 in the 1st iteration)
        so there are totally 2^6 = 64 possible states. We can record the possible states, and change which iteration begins to
        form a circle and which state is the begining circle.
        */
        vector<int> state(8,0);
        for (int i=1; i<7; i++)
        {
         if (cells[i-1]==cells[i+1])
             state[i] = 1;
         else
             state[i] = 0;
        }
        if (N==1)
         return state;
        vector<vector<int>> states;
        states.push_back(state);   
        vector<int> currState(8,0);
        int circleStart = -1;
        int circleEnd = -1;
        int circleLen = 0;
        for (int i=1; i<64; i++)
        {
            for (int j=1; j<7; j++)
            {
                if (state[j-1]==state[j+1])
                    currState[j] = 1;
                else
                    currState[j] = 0;
            }
            for (int j=0; j<states.size(); j++)
            {
                if (states[j]==currState)
                {
                    circleStart = j;
                    circleEnd = i;
                    break;                
                }
            }
            if (circleStart!=-1)
            {
                break;
            }
            state = currState;
            states.push_back(state);
        }
        if (circleStart>=0)
        {
            circleLen = circleEnd - circleStart;
        }
        if (N<=circleEnd)
            return states[N-1];
        if (circleLen==1)
            return states[0];
        cout<<circleStart<<" "<<circleEnd<<endl;
        int ind = (N-circleStart)%circleLen;
        int des = ind + circleStart-1;
        if (des<0)
            des = des + circleLen;
        return states[des];
    }
};
