vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int>nxtCnt(n,0);

        for(int i=n-2;i>=0;i--){
            if(security[i]<=security[i+1]) nxtCnt[i]=nxtCnt[i+1]+1;
            else nxtCnt[i]=0;
        }

        vector<int>ans;
        int prevCnt=0;
        for(int i=0;i<n;i++){
            if(i and security[i]<=security[i-1]) prevCnt+=1;
            else prevCnt=0;
            if(prevCnt>=time and nxtCnt[i]>=time) ans.push_back(i);
        }
        return ans;
    }
