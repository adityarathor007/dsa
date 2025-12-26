int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum=INT_MIN,curMax=0;
        int minSum=INT_MAX,curMin=0;
        int total=0;

        for(int a:nums){
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }

        return maxSum>0?max(maxSum,total-minSum):maxSum;
    }
