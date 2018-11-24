class Solution {
public:
    string intToRoman(int num) {
         string res = "";
         int t;
         t = num/1000;
         if (0<t && t<4)
         {
             for (int i=0;i<t;i++)
                 res = res+'M';
         }
        num = num%1000;
        t = num/100;
        if (0<t&& t<4)
        {
            for(int i=0;i<t;i++)
                res = res + 'C';
        }
        else if (t==4)
            res = res+'C'+'D';
        else if (t==5)
            res = res+'D';
        else if (5<t&& t<9)
        {
            res = res+'D';
            for (int i=0;i<t-5;i++)
                res = res +'C';
        }
        else if (t==9)
            res = res+'C'+'M';
        
        num = num%100;
        t = num/10;
         if (0<t&& t<4)
        {
            for(int i=0;i<t;i++)
                res = res + 'X';
        }
        else if (t==4)
            res = res+'X'+'L';
        else if (t==5)
            res = res+'L';
        else if (5<t && t<9)
        {
            res = res+'L';
            for (int i=0;i<t-5;i++)
                res = res +'X';
        }
        else if (t==9)
            res = res+'X'+'C';
        
        num = num%10;
        t = num/1;
         if (0<t && t<4)
        {
            for(int i=0;i<t;i++)
                res = res + 'I';
        }
        else if (t==4)
            res = res+'I'+'V';
        else if (t==5)
            res = res+'V';
        else if (5<t && t<9)
        {
            res = res+'V';
            for (int i=0;i<t-5;i++)
                res = res +'I';
        }
        else if (t==9)
            res = res+'I'+'X';
        
        return res;
    }
};

class Solution {
public:
    string intToRoman(int num) {
        string dict[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};  
        string ret;
        for(int i=0; i<13; i++) {
            if(num>=val[i]) {
                int count = num/val[i];
                num %= val[i];
                for(int j=0; j<count; j++) {
                    ret.append(dict[i]);
                }
            }
        }
        return ret;
    }
};
