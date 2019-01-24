class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        /*
        We preprocess the email, and then store them in a unordered_set
        */
        if (emails.empty())
            return 0;
        unordered_set<string> myset;
        for (string s : emails)
        {
            //preprocess s
            string news = "";
            bool flag = 0;
            for (int i=0; i<s.length(); i++)
            {
                char c = s[i];
                if (flag)
                    news += c;
                else
                {
                    if (c=='+')
                    {
                        while (s[i]!='@')
                        {
                            i++;
                        }
                        if (s[i]=='@')
                        {
                            news += s[i];
                            flag = 1;
                        }
                            // flag = 1;
                    }
                    else if (c!='.')
                        news += c;
                }
                    
                if (c=='@')
                {
                    news +=c;
                    flag = 1;
                }
            }
            myset.insert(news);
        }
        return myset.size();
    }
};
