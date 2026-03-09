bool recCheck(int i,vector<int>& res,int targetLen, vector<int>&matchsticks){
        if(i==matchsticks.size()){
            return res[0]==targetLen and res[1]==targetLen and res[2]==targetLen and res[3]==targetLen;
        }

        int stick=matchsticks[i];
        for(int k=0;k<4;k++){
            if(res[k]+stick>targetLen) continue; //if exceeding the targetLen
            if(k>0 and res[k]==res[k-1]) continue; //early pruning as same case done before for one side
            res[k]+=stick;
            if(recCheck(i+1,res,targetLen,matchsticks)) return true;
            res[k]-=stick;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        if(n<4) return false;
        int sum=0;
        for(int num:matchsticks){
            sum+=num;
        }
        if(sum%4) return false;
        int targetLen=sum/4;
        vector<int>res(4,0);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return recCheck(0,res,targetLen,matchsticks);
    }
