class LogSystem {
public:
    LogSystem() {
                
    }
    
    void put(int id, string timestamp) {
        mymap[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> res;
        //adjust s and e according to gra
        
        if (gra=="Year")
        {
                s = s.substr(0,4)+":00:00:00:00:00";
                e = e.substr(0,4)+":12:31:23:59:59";
                // break;            
        }
        else if (gra=="Month")
        {
                s = s.substr(0,7)+":00:00:00:00";
                e = e.substr(0,7)+":31:23:59:59";
                // break;                            
        }
        else if (gra=="Day")
        {
                s = s.substr(0,10)+":00:00:00";
                e = e.substr(0,10)+":23:59:59";            
        }
        else if (gra=="Hour")
        {
                 s = s.substr(0,13)+":00:00";
                e = e.substr(0,13)+":59:59";
                // break;           
        }
        else if (gra == "Minute")
        {
               s = s.substr(0,16)+":00";
                e = e.substr(0,16)+":59"; 
        }
        cout<<s<<" haha "<<e<<endl;

        auto sit = mymap.lower_bound(s);
        auto eit = mymap.upper_bound(e);
        while (sit!=mymap.end()&&sit!=eit)
        {
            res.push_back(sit->second);
            sit++;
        }
        return res;
    }
private:
    map<string,int> mymap;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
