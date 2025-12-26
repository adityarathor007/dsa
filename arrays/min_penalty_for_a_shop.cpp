class Solution {
public:
    int bestClosingTime(string customers) {
        int prev_N=0,future_Y=0;

        for(char ch:customers){
            if(ch=='Y')future_Y+=1;
        }

        int min_penalty=INT_MAX,ans=0;
        int n=customers.size(),i=0;
        while(i<n){
            char ch=customers[i];
            int curr_penalty=future_Y+prev_N;

            if(curr_penalty<min_penalty){
                min_penalty=curr_penalty;
                ans=i;
            }

            if(ch=='Y') future_Y-=1;
            else prev_N+=1;
            i+=1;
        }

        int curr_penalty=future_Y+prev_N;
        if(curr_penalty<min_penalty){
            min_penalty=curr_penalty;
            ans=i;
        }

        return ans;

    }
};
