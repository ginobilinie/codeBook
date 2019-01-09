class Solution {
public:
    vector<string> res;
    vector<string> ipvec;//store part of the ip
    vector<string> restoreIpAddresses(string s) {
        string tmp="";
        if (s.length()<4||s.length()>12)
            return res;
        dfs(s,0);
        return res;
    }
    void dfs(string s, int currInd)
    {
        if (s.length()==currInd)
        {
            if (ipvec.size()==4)
            {
                string ips = ipvec[0]+'.'+ipvec[1]+'.'+ipvec[2]+'.'+ipvec[3];
                res.push_back(ips);
            }
            return;
        }
        
        for (int step=1; step<4; step++)
        {
            if (currInd+step>s.length())
                continue;
            string pid = s.substr(currInd,step);
            if (pid.length()>1&&pid[0]=='0')
                continue;
            int tmp = 0;
            for (int i=0; i<pid.length(); i++)
            {
                tmp = tmp*10 + pid[i]-'0';
            }
            if (tmp>255)
                continue;
            ipvec.push_back(pid);
            dfs(s,currInd+step);
            ipvec.pop_back();
        }

    }
    
};
