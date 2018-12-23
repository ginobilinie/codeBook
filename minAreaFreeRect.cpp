class Solution {
public:
    
    struct POINT{
        int x;
        int y;
    } mypoints[50], fpoints[4];
    
    static bool compare(POINT a, POINT b)
    {
        if (a.x==b.x)
            return a.y<b.y;
        return a.x<b.x;
    }
    int dis(POINT a, POINT b)
    {
        return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
 
    bool mid(POINT a, POINT b, POINT c, POINT d)
    {
        if(a.x + b.x == c.x + d.x && a.y + b.y == c.y + d.y) return true;
            return false;
    }
    
    double isRectangle(struct POINT* p)
    {
        for(int i = 0; i < 4; i ++){
            for(int j = i + 1; j < 4; j ++)
            if(p[i].x == p[j].x && p[i].y == p[j].y)
                return -1;
        }
        if(dis(p[0], p[1]) == dis(p[2], p[3]) && mid(p[0], p[1], p[2], p[3]) )
            return sqrt(dis(p[0],p[2]))* sqrt(dis(p[0],p[3]));
        if(dis(p[0], p[2]) == dis(p[1], p[3]) && mid(p[0], p[2], p[1], p[3]))
            return sqrt(dis(p[0],p[1]))*sqrt(dis(p[0],p[3]));
        if(dis(p[0], p[3]) == dis(p[1], p[2]) && mid(p[0], p[3], p[1], p[2]))
           return sqrt(1.0*dis(p[0],p[1]))*sqrt(1.0*dis(p[0],p[2]));
        return -1;
    }

    
    
    double minAreaFreeRect(vector<vector<int>>& points) {
        int len = points.size();
        for (int i=0; i<len; i++)
        {
            mypoints[i].x = points[i][0];
            mypoints[i].y = points[i][1];
        }
        // sort(mypoints, mypoints+len,compare);//sort in the x direction
        double minArea = INT_MAX;
        for (int i=0;i<len-3;i++)
        {
            fpoints[0] = mypoints[i];
            for (int j=i+1; j<len-2; j++)
            {
                fpoints[1] = mypoints[j];
                for (int k = j+1; k<len-1; k++)
                {
                    fpoints[2] = mypoints[k];
                    for (int l = k+1; l<len; l++)
                    {
                        
                        fpoints[3]= mypoints[l];
                        double area = isRectangle(fpoints);
                        if (area>0)
                            if (area<minArea)
                                minArea = area;
                    }
                }

            }

        }
        if (abs(minArea-INT_MAX)<0.0000001)
            return 0;
        return minArea;
    }
};
