int mySqrt(int x) {
       int i=0,j=46340;
       int ans=-1;

       while(i<=j){
        int mid=i+(j-i)/2;
        int prd=mid*mid;
        if(prd==x) return mid;
        if(prd>x){
            ans=mid;
            j=mid-1;
        }
        else i=mid+1;
       }

       if(ans==-1) return 46340;
       return ans-1;
}
