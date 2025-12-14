 int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        int prev=0;
        for(int i=31;i>=0;i--){
            int l=left>>i&1;
            int r=right>>i&1;
            if(l^r) return ans;
            ans|=((l&r)<<i);
        }


        return ans;
    }
