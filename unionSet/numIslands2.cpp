class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        /*
        once again, we can use union set with path compression to solve this problem:
        find: O(log(m*n)), union: O(log(m*n)) for each operation
        */
        if (m*n==0)
            return {};
        vector<int> parent(m*n+1);
        for (int i=0; i<m*n+1; i++)
            parent[i] = i;
        vector<int> res;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        int k = positions.size();
        int cnt = 0;
        vector<vector<int>> grid(m,vector<int>(n,0));
        for (int i=0; i<k; i++)
        {
            auto pos = positions[i];
            int x = pos.first, y = pos.second;
            grid[x][y] = 1;
            int loc = x*n+y;
            int pmother = findparent(loc, parent);
            for (int j=0; j<4; j++)
            {
                int px = x+dx[j];
                int py = y+dy[j];
                if (px<0||px>=m||py<0||py>=n||grid[px][py]==0)
                    continue;
                int tt = px*n + py;
                int pchild = findparent(tt, parent);
                if (pmother!=pchild)
                {
                    cnt++;
                    parent[pchild] = pmother;
                }
            }
            res.push_back(i+1-cnt);
        }
        return res;
    }
    
    int findparent(int ind, vector<int>& parent)
    {
        while (ind!=parent[ind])
        {
            parent[ind] = parent[parent[ind]];
            ind = parent[ind];
        }
        return parent[ind];
    }
};
