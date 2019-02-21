class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> dict;
        for (char c : t)
        {
            dict[c]++;
        }
        int num = t.length();
        //start records the history based left node, and left marks the current left node
        int i=0, start=0, left=0, len = INT_MAX;
        for (; i<s.length(); i++)
        {
            if (dict.count(s[i]))//dict[s[i]]>0 is very important
            {
                if (dict[s[i]]>0)
                    num--;
                dict[s[i]]--;
            }
            while (num<=0)//reduce the length of the substring: s[left to i],left and i included
            {
                //cout<<"len:"<<len<<" left:"<<left<<endl;
                if (len>i-left+1)
                {
                    len = i - left + 1;
                    start = left;
                }
                // len = (i-left+1)<len?(i-(start=left)+1):len;
                if (dict.count(s[left]))
                {
                   if (dict[s[left]]==0)
                        num++;
                    dict[s[left]]++;
                }
                left++;
            }
        }
        if (len==INT_MAX) return "";
        // cout<<start<<" "<<len<<endl;
        return s.substr(start,len);
    }
};
