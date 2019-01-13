class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        string outline = "";
        int line = 0;
        int currInd = 0;
        if (numRows==1)
            return s;
        while(line<numRows)
        {
            if (line==0||line==numRows-1)
            {
                currInd = line;
                outline = outline + s[currInd];
                while(currInd+2*numRows-2<len)
                {
                    currInd = currInd+2*numRows-2;
                    outline = outline + s[currInd];
                }
                line++;
            }
            else
            {
                currInd = line;
                outline = outline + s[currInd];
                currInd = currInd+2*numRows-(line+1)*2;
                int cnt = 0;
                while(currInd<len)
                {
                    outline = outline + s[currInd];
                    if(cnt%2)
                        currInd = currInd+2*numRows-(line+1)*2;
                    else
                        currInd = currInd + line*2;
                    cnt++;
                }
                line++;
            }
        }
        return outline;
    }
};
