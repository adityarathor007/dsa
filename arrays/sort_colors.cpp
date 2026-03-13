void sortColors(vector<int>& nums){
    int n=nums.size();
    int l=0,mid=0,h=n-1; //[0,l-1] will be 0th color [l,h-1] will be the 1st color and [h,n-1] will be the last color
    while(mid<=h){
        if(nums[mid]==0){
            swap(nums[l],nums[mid]);
            mid+=1;
            l+=1;
        }
        else if(nums[mid]==1) mid+=1;
        else{
            swap(nums[mid],nums[h]);
            h-=1;
        }
    }

}
