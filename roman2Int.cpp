class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        string dict[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int num[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int currInd4Str = 0;
        int currInd4Dict = 0;
        while (currInd4Dict< 13 && currInd4Str<s.length())
        {
            string currDictItem = dict[currInd4Dict];
            string tmp = s.substr(currInd4Str,currDictItem.length());
            if (tmp == currDictItem)
            {
                res = res + num[currInd4Dict];
                currInd4Str = currInd4Str + currDictItem.length();
            }
            else
            {
                currInd4Dict++;
            }
        }
        return res;
    }
};
