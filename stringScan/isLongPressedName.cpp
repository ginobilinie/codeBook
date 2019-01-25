class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name==""&&typed=="")
            return 1;
        if (name==""&&typed!="")
            return 0;
        if (name.length()>typed.length())
            return 0;
        int p1=0, p2=0;
        bool res = 1;
        while (p1<name.length()&&p2<typed.length())
        {
            if(name[p1]!=typed[p2])
            {
                res = 0;
                break;
            }
            int cnt1 = 0;
            while(p1+1<name.length()&&name[p1]==name[p1+1])
            {
                p1++;
                cnt1++;
            }
            int cnt2 = 0;
            while(p2+1<typed.length()&&typed[p2]==typed[p2+1])
            {
                p2++;
                cnt2++;
            }
            if (cnt1>cnt2)
            {
                res = 0;
                break;
            }
            p1++;
            p2++;
        }
        if (p1<name.length())
            res = 0;
        return res;
    }
};
