int computeMaxArea(vector<int>& curr){
        int n=curr.size(),max_area=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and curr[st.top()]>curr[i]){
                int h=curr[st.top()];
                st.pop();
                int pse_i=!st.empty()?st.top():-1;
                int w=i-pse_i-1;
                max_area=max(max_area,h*w);
            }
            st.push(i);
        }

        while(!st.empty()){
            int h=curr[st.top()];
            st.pop();
            int pse_i=!st.empty()?st.top():-1;
            int w=n-pse_i-1;
            max_area=max(max_area,h*w);
        }
        return max_area;
    }

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]){
                    if(matrix[i-1][j]) matrix[i][j]+=matrix[i-1][j];
                }
            }
        }

        int ans=0;
        for(int i=0;i<m;i++){
            vector<int>curr(matrix[i]);
            sort(curr.begin(),curr.end());
            ans=max(ans,computeMaxArea(curr));
        }

        return ans;
    }
