 int rangeBitwiseAnd(int left, int right) {
       int ans=0;
       for(int i=31;i>=0;i--){
        int lb=(left>>i)&1;
        int rb=(right>>i)&1;
        if(lb^rb) return ans;  //because if the bits are same then changes will happen on its left side for the numbers between it and this bit remain same for all the numbers in between
        ans+=(lb&rb)<<i;
       }
       return ans;
    }
