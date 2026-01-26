     bool increasingTriplet(vector<int>& nums) {
         int first=INT_MAX,second=INT_MAX;
        for(int num:nums){
            if(num<first) first=num;
            else if(num>first and num<second) second=num;  //gurantteee that first_smallest will occur before the second smallest
            else if(num>first and num>second) return true; //the number is greater than the first and second num
        }
        return false;


    }
