 int findMaxPrice(int i,int len_left,vector<int>&price,vector<vector<int>>&dp){
        if(len_left<=0 || i<0){
            return 0;
        }



        if(dp[i][len_left]!=-1){
            return dp[i][len_left];
        }

        int n=price.size();

        int notCut=findMaxPrice(i-1,len_left,price,dp);

        int cut=0;
        int rod_len=i+1;
        if(rod_len<=len_left){
            cut=price[i]+findMaxPrice(i,len_left-rod_len,price,dp);
        }


        return dp[i][len_left]=max(cut,notCut);
    }



    int cutRod(vector<int> &price) {
        // code here
        int rod_len=price.size();
        vector<vector<int>>dp(rod_len,vector<int>(rod_len+1,-1));
        return findMaxPrice(rod_len-1,rod_len,price,dp);
    }
