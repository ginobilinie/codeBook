class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
      /*let's use union find to solve this problem
      The main problem is that grid is a 2D MATRIX, how can we use 1d vector to represent 
      the parent of each node? We can use rows*cols+1 based vector to represent each item.
      A next question: how we determine the parent-child relationship, in other words, how we know
      they are in a same group? We can check 4 directions, if one point is neighouring to the current visited 
      point, then we make a union operation
        */
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> parent(rows*cols+1,0);
        for (int i=0; i<rows*cols+1; i++)
            parent[i] = i;
        int cnt = 0;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
                if (grid[i][j]=='1')
                    cnt++;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        // vector<vector<bool>> used(rows,vector<bool>(cols,0));
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
            {
                if (grid[i][j]=='0')
                    continue;
                // used[i][j] = 1;
                int fixpos = i*cols+j;
                int pmother = findparent(fixpos,parent);
                for (int k=0; k<4; k++)
                {
                    int px = i+dx[k];
                    int py = j+dy[k];
                    // if (px<0||px>=rows||py<0||py>=cols||used[px][py]||grid[px][py]=='0')
                    if (px<0||px>=rows||py<0||py>=cols||grid[px][py]=='0')
                        continue;
                    // used[px][py] = 1;
                    int pos = px*cols+py;
                    int pchild = findparent(pos,parent);
                    // cout<<"ij:"<<i<<" "<<j<<" pxpy:"<<px<<" "<<py<<" "<<pchild<<" "<<pmother<<endl;
                    if (pmother!=pchild)
                    {
                        parent[pchild] = pmother;
                        cnt--;
                    }
                }
            }
        return cnt;
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
