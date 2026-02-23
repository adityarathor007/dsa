int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(int ans:answers){
            mp[ans]+=1;
        }

        int total=0;
        for(auto [num,cnt]:mp){
            int sets=cnt/(num+1);
            if(cnt%(num+1)) sets+=1;
            total+=(sets*(num+1));
        }

        return total;
    }
