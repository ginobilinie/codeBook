#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

int largestRectangleArea1(vector<int> heights) {
        stack<int> mystack;
        int maxVal = 0, rightIndex = 0;
        while(rightIndex < heights.size()) 
        {
            // All new bars are seen as potential right bar
            int rightHeight = heights[rightIndex]; 
            // Only increment rightIndex, when pushed
            //find the first decreased item, and we then compute the height among bars before this first decreased item 
            if (mystack.empty() || heights[mystack.top()] < rightHeight) 
            {
                mystack.push(rightIndex++); 
                //rightHeight = heights[rightIndex];
            }
            else
            {     
                // Be careful that stack only store index, we still need heights[index] to get height
                int curHeight = heights[mystack.top()];
                mystack.pop();
                // Be careful of case of no left bar
                int leftIndex = mystack.empty() ? -1 : mystack.top();  
                int tmp = (rightIndex - leftIndex - 1) * curHeight;
                if (tmp>maxVal)
                    maxVal = tmp;
            }                  
        }
        while(!mystack.empty())
        {
            int curHeight = heights[mystack.top()]; 
            mystack.pop();
            int leftIndex = mystack.empty() ? -1 : mystack.top(); 
            // here rightIndex == heights.length
            int tmp = (rightIndex - leftIndex - 1) * curHeight;
            if (tmp>maxVal)
                maxVal = tmp;
        }
        return maxVal;
    }


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
				break;
			barVal = heights[currInd];
            while (!s.empty()&&heights[s.top()]>=barVal)
            {
                leftInd = s.top();
                leftHeight = heights[leftInd];
                s.pop();
                //now we can compute the area between the leftInd (inclusive) to the currInd (exclusive)
				width = currInd -leftInd;
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
            //now we can compute the area between the leftInd (inclusive) to the currInd (exclusive)
            int width = currInd -leftInd;
            int tmp = width*leftHeight;
            if (tmp>maxVal)
                maxVal = tmp;
        }
        
        return maxVal;
    }


int main()
{
	string s = "1.89(9)";
	string t = "1.90";
	vector<int> data(6,0);
	data[0]=2;
	data[1]=1;
	data[2]=3;
	data[3]=2;
	data[4]=2;
	data[5]=3;
	
	largestRectangleArea1(data);
	cout<<"test"<<endl;
	return 0;
}
