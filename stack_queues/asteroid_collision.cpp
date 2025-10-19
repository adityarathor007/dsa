class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int val:asteroids){
            if(st.empty() or val>0) st.push(val); 
            else{
                if(st.top()<0) st.push(val);
                else{
                    while(!st.empty() and st.top()>0 and st.top()<abs(val)){
                        st.pop();
                    }
                    if(st.empty() or st.top()<0) st.push(val); //if the stack is empty or top contains negative element then the push the new value
                    else if(st.top()==abs(val)) st.pop();
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};