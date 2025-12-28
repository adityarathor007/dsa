class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cars;
        int n=position.size();

        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end(),greater<pair<int,int>> ());

        stack<double>st;

        for(int i=0;i<n;i++){
            int postn=cars[i].first,spd=cars[i].second;
            double time_taken=(double) (target-postn)/spd;
            if(st.empty() || st.top()<time_taken){
                st.push(time_taken);
            }
        }

        return st.size();
    }
};