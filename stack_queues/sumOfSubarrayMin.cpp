class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // int ans=0;
        // int n=int(arr.size());
        // int large_num=1e9+7;

        // for(int i=0;i<n;i++){
        //     int curr_min=arr[i];
        //     ans=(ans+curr_min)%large_num;
        //     for(int j=i+1;j<n;j++){
        //         curr_min=min(arr[j],curr_min);
        //         ans=(ans+curr_min)%large_num;
        //     }
        // }

        // return ans;


        int n=int(arr.size());
        vector<int>prevSmaller(n,-1),nextSmaller(n,n);
        stack<int>s;
        int MOD=1e9+7;

        // previous smaller element (Strictly less)
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            prevSmaller[i]=s.empty()?-1:s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // next smaller element(Less than or equal - for uniquness in duplicates)
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            nextSmaller[i]=s.empty()?n:s.top();
            s.push(i);
        }

        long long sum=0;

        for(int i=0;i<n;i++){
            long long left=(i-prevSmaller[i])%MOD;
            long long right=(nextSmaller[i]-i)%MOD;
            sum=(sum+left*right*arr[i])%MOD;

        }

        return int(sum);


    }
};
