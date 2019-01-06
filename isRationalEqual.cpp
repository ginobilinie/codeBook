class Solution {
public:
     bool isRationalEqual(string S, string T) {
        int len1 = S.length();
        int len2 = T.length();
        
        bool res = 1;
        int ps=0, pt=0;
        string is="", it="";
        while (ps<len1&&pt<len2)
        {
            if (S[ps]=='.'&&T[pt]=='.')
            {
                ps++;
                pt++;
                break;    
            }
            // if (S[ps]!=T[pt])
            // {
            //     res = 0;
            // }
			is += S[ps];
            it += T[pt];
            ps++;
            pt++;
        }
        //the first pointer after the '.'
        string ds="";
        string rs="";
        if (ps<len1&&S[ps]=='.')
			ps++;
		if (pt<len2&&T[pt]=='.')
			pt++;
        while(ps<len1)
        {
            while (ps<len1&&S[ps]!='(')
                ds += S[ps++];
            //now ps to the '('
            while (++ps<len1&&S[ps]!=')')
                rs += S[ps];
            ps++;
        }

        //the first pointer after the '.'
        string dt="";
        string rt="";
        while(pt<len2)
        {
            while (pt<len2&&T[pt]!='(')
                dt += T[pt++];
            //now ps to the '('
            while (++pt<len2&&T[pt]!=')')
                rt += T[pt];
            pt++;
        }
        while (rt.length()!=0&&dt.length()+rt.length()<15)
        {
            dt += rt;
        }      
        while (rs.length()!=0&&ds.length()+rs.length()<15)
        {
            ds += rs;
        }   
        
//         for (int i=0; i<ds.length()&&i<dt.length(); i++)
//         {
//             if (ds[i]!=dt[i])
//             {
//                 res = 0;
//                 break;
//             }
//         }
        
        // string ms = is+'.'+ds;
        // string mt = it+'.'+dt;
        string ms = is+ds;
        string mt = it+dt;
         if (ms.length()>12)
         {
             ms = ms.substr(0,12);
             int ls = 12;
             while(--ls>=0&&ms[ls]=='9');
             if (12-ls>=4)//repeated
             {
                 if (ls>=0)
                 {
                     ms[ls] = ms[ls]-'0'+'1';
                     for (int k=ls+1; k<12; k++)
                         ms[k] = '0';
                 }
                 else
                 {
                     ms = '1'+ms;
                 }
             }
         }
         if (mt.length()>12)
         {
             mt = mt.substr(0,12);
             int lt = 12;
             while (--lt>=0 && mt[lt]=='9');
             if (12-lt>=4)//repeated
             {
                 if (lt>=0)
                 {
                     mt[lt] = mt[lt] - '0' + '1';
                     for (int k=lt+1; k<12; k++)
                         mt[k] = '0';
                 }
                 else
                 {
                     mt = '1' + mt;
                 }
             }
         }
         int ii;
         for (ii=0; ii<ms.length()&&ii<mt.length(); ii++)
         {
             if (ms[ii]!=mt[ii])
             {
                 res = 0;
                 break;
             }
         }
         
         ps = ii;
         pt = ii;
         while(ps<ms.length())
         {
             if (ms[ps++]!='0')
             {
                 res = 0;
                 break;
             }
         }
         while (pt<mt.length())
         {
             if (mt[pt++]!='0')
             {
                 res = 0;
                 break;
             }
         }
// 		string yp= ms.substr(0,12);
        
         
//         if (ms=="1."&&mt.substr(0,12)=="0.9999999999" ||mt=="1."&&ms.substr(0,12)=="0.9999999999")
//             res = 1;
         
//          double mss = stod(ms);
//          double mtt = stod(mt);
         
//          if (abs(mss-mtt)<1e-12)
//              res = 1;
        return res;
    }
};
