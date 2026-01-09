int recCalculator(int i,int j,vector<int>&nums1,vector<int>&nums2){
        if(i==nums1.size() or j==nums2.size()) return -1e9;

        if(dp[i][j]!=INT_MIN) return dp[i][j];

        int cp=nums1[i]*nums2[j];
        int np=recCalculator(i+1,j+1,nums1,nums2);;

        int o1=max(cp,cp+np);

        int o2=recCalculator(i,j+1,nums1,nums2);
        int o3=recCalculator(i+1,j,nums1,nums2);

        // cout<<i<<" "<<j<<endl;
        // cout<<o1<<" "<<o2<<" "<<o3<<endl;
        return dp[i][j]=max(o1,max(o2,o3));
    }

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
       int m=nums1.size(),n=nums2.size();
       dp.assign(m,vector<int>(n,INT_MIN));

       int ans=recCalculator(0,0,nums1,nums2);
       return ans;
}
