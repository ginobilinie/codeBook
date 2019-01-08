class Solution {
public:
int largestRectangleArea(vector<int> heights) {
        if (heights.empty())
            return 0;
        int sz = heights.size();
        
        stack<int> s;//to store the current incremental 
        
        int currInd = 0, tmp, leftInd, leftHeight;
        int maxVal = INT_MIN;
        int barVal, width;
        while (currInd<sz)
        {
            //for the incremental data, store them into the stack
            //stop when we first encounter the decreased item
            while (s.empty()|| currInd<sz && heights[s.top()]<heights[currInd])
            {
                s.push(currInd++);
            }
            //deal with the stack
            //if the left side values are still larger than the currInd's value, 
            //we can compute the area and record the maximum value
	
			if (currInd==sz)
				barVal = heights[currInd-1];
			else
				barVal = heights[currInd];
            while (!s.empty()&&heights[s.top()]>=barVal)
            {
                leftInd = s.top();
                leftHeight = heights[leftInd];
                s.pop();
                //now we can compute the area between the s.top() (exclusive) to the currInd (exclusive)
                //it is very important to realize it is s.top() instead of leftInd here, since the intermedia values 
                //have the same value in default in the stack
				width = currInd - (s.empty()?-1:s.top())-1;
                int tmp = width*leftHeight;
                if (tmp>maxVal)
                    maxVal = tmp;
            }
        }
        
        //deal with the remaining items in stack
        //if the left side values are still larger than the currInd's value, 
        //we can compute the area and record the maximum value
        while (!s.empty())
        {
            leftInd = s.top();
            leftHeight = heights[leftInd];
            s.pop();
            //now we can compute the area between the s.top (exclusive) to the currInd (exclusive)
            int width = currInd - (s.empty()?-1:s.top())-1;
            int tmp = width*leftHeight;
            if (tmp>maxVal)
                maxVal = tmp;
        }
        
        return maxVal;
    }
};
