class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    // LCM using GCD
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
    long long maxScore(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=-1;i<n;i++){
            long long g=0,l=1;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                g=gcd(g,nums[j]);
                l = lcm(l, nums[j]);
            }
            ans = max(ans, g * l)
        }

        return ans;
    }
};
