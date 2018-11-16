#include<iostream>
#include<vector>
#include<map>
using namespace std;

//brute force, O(n^2) for time complexity, O(1) for space complexity
//can work for repeating values
 vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> v;
        int indX = -1, indY = -1;
        for (int i=0; i<nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                if (nums[i]+nums[j]==target)
                {
                    indX = i;
                    indY = j;
                    break;
                }
            }
        }
		v.push_back(nums[indX]);
		v.push_back(nums[indY]);
        return v;
    }

//hash table, O(n) for time complexity, O(n) for space complexity
//can work for repeating values
 vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> v;
        map<int,vector<int>> m;
        for (int i=0; i<nums.size(); i++)
        {
            if (m.count(nums[i])>0)
                m[nums[i]].push_back(i);
            else
            {
                vector<int> vect;
                vect.push_back(i);
                m.insert(std::pair<int,vector<int>>(nums[i],vect));
            }
        }
        int indX = 0, indY = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (m.count(target-nums[i])>0)
            {
                vector<int> vec = m[target-nums[i]];
                for(int j=0;j<vec.size();j++)
                    if(vec[j]>i)
                    {
                        indX=i;
                        indY=vec[j];
			break;
                    }
            }
            
        }
		v.push_back(indX);
		v.push_back(indY);
        return v;
    }

int main()
{	
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(7);
	vec.push_back(7);
	vec.push_back(10);
	vector<int> res = twoSum1(vec,9);
	printf("res[0]:%d, res[1]:%d",res[0],res[1]);
	int x;
	cin>>x;
}

