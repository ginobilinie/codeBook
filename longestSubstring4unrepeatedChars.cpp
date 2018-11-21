#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include<sstream>
#include<map>
#include<assert.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> maxLen2CurrInd;//should include current char
       map<char,int> localMap;//char and its latest index
       int lastInd4UnrepeatLocation=0;//the last index 4 unrepeated location till the current index
       localMap[s[0]] = 0;
        int globalMaxLen = 1;
		maxLen2CurrInd.push_back(1);
        int maxLen = s.length();
       for (int i=1;i<maxLen;i++)
       {
           if (localMap.count(s[i]))
           {
               if (lastInd4UnrepeatLocation<=localMap[s[i]])
               {
				   maxLen2CurrInd.push_back(i-localMap[s[i]]);
                    lastInd4UnrepeatLocation = localMap[s[i]]+1;
               }

               else
               {
				   maxLen2CurrInd.push_back(i-lastInd4UnrepeatLocation+1);
               }
               if (maxLen2CurrInd[i]>globalMaxLen)
                   globalMaxLen = maxLen2CurrInd[i];
               localMap[s[i]] = i;
           }
           else
           {
			   maxLen2CurrInd.push_back(maxLen2CurrInd[i-1]+1);
               if (maxLen2CurrInd[i]>globalMaxLen)
                   globalMaxLen = maxLen2CurrInd[i];
               localMap[s[i]] = i;
           }
       }
	   if (s=="")
		   return 0;
       return globalMaxLen;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = line;
        
        int ret = Solution().lengthOfLongestSubstring(s);

        //string out = to_string(ret);
        cout << ret << endl;
    }
    return 0;
}
