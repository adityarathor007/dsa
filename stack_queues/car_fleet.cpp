class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>data;
        int n=position.size();
        for(int i=0;i<n;i++){
            data.push_back({position[i],speed[i]});
        }
        sort(data.begin(),data.end());
        stack<double>st;

        // logic is that if a vehicle becomes a part of fleet time taken to reach the target should be less than or equal to the time taken by the any upcoming vehicle reaching target
        for(auto [post,sp]:data){
            double time=(double)(target-post)/sp;
            while(!st.empty() and st.top()<=time) st.pop();
            st.push(time);
        }

        return st.size();

    }
};
