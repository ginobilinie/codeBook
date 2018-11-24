
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int maxV = 0;
        for (int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                
                int volume = (j-i)* (height[i]>height[j]?height[j]:height[i]);
                if (volume>maxV)
                    maxV = volume;
            }

        }
        return maxV;
    }
};

public class Solution {
    public int maxArea(int[] height) {
        int maxarea = 0, l = 0, r = height.length - 1;
        while (l < r) {
            maxarea = Math.max(maxarea, Math.min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
}
