int minimumDeletions(string s) {
        // at every index we have to decide that all before b(s) should be a and after that index all a(s) should be b
        // we need to find that index where we have to do min conversions
        int cnta=0,cntb=0;
        for(char ch:s) cnta+=(ch&1);


        int min_cost=INT_MAX;
        for(char ch:s){
            cnta-=(ch&1);
            min_cost=min(min_cost,cnta+cntb);
            cntb+=(~ch&1);
        }

        return min_cost;
    }
