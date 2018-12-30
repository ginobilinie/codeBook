#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

    char dict[5]={'a', 'e', 'i', 'o', 'u'};
string str2lowercase(string s)
{
    if (s=="")
        return s;
    string res=s;
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]<='Z'&&s[i]>='A')
            res[i] = s[i]+32;
    }
    return res;
}        

vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    int queryLen = queries.size();
    int wordlistLen = wordlist.size();
        
    vector<string> resVec;
    vector<string> res;
    string tmp="";
    // vector<string> wordlist_lowercase;
    map<string, int> wordlistMap;
    map<string, int> lowercasewordlistMap;
    map<string, int> generalmatchwordlistMap;
    for (int i=0; i<wordlistLen; i++)
    {
        tmp = wordlist[i];
        if (wordlistMap.count(tmp)==0)
        {
            wordlistMap[tmp] = i;
        }
        // tmp = wordlist[i];
        tmp = str2lowercase(tmp);
        if (lowercasewordlistMap.count(tmp)==0)
        {
            lowercasewordlistMap[tmp] = i;
        }
        for (int j=0; j<tmp.length(); j++)
        {
            for (int k=0; k<5; k++)
            {
                if (tmp[j]==dict[k])
                    tmp[j]='?';
            }
        }
        if (generalmatchwordlistMap.count(tmp)==0)
            generalmatchwordlistMap[tmp] = i;
    }
        
    // sort(wordlist.begin(),wordlist.end());
    for (int ii=0; ii<queryLen; ii++)
    {
        string query = queries[ii];
        string lowercasequery = str2lowercase(query);
        int fff = 0; //0-no match, 1-exact match, 2-not exact match
        if (wordlistMap.count(query)>0)//exact-match
            res.push_back(query);
        else if (lowercasewordlistMap.count(lowercasequery)>0)//capital case
        {
            int ind = lowercasewordlistMap[lowercasequery];
            res.push_back(wordlist[ind]);
        }
        else
        {
            string generalmatchquery = lowercasequery;
            bool flag = false;
            //change 'aeiou' to '?'
            for (int i=0; i<lowercasequery.length(); i++)
            {
                for (int j=0; j<5; j++)
                {
                    if (lowercasequery[i]==dict[j])
                        generalmatchquery[i]='?';
                }
            }
                
            if (generalmatchwordlistMap.count(generalmatchquery)>0)
                res.push_back(wordlist[generalmatchwordlistMap[generalmatchquery]]);
            else
                res.push_back("");                       
        }
    
    }
    return res;
}


int main()
{
	vector<string> wordlist, queries;

	wordlist.push_back("KiTe");
	wordlist.push_back("kite");
	wordlist.push_back("hare");
	wordlist.push_back("Hare");

	/*
	queries.push_back("kite");
	queries.push_back("Kite");
	queries.push_back("KiTe");
	queries.push_back("Hare");
	queries.push_back("HARE");
	queries.push_back("Hear");
	queries.push_back("hear");
	*/
	queries.push_back("keti");
	queries.push_back("keet");
	queries.push_back("keto");

	spellchecker(wordlist,queries);
	return 0;
}
