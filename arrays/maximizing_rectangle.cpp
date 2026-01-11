class Solution {
public:
    int computeLargestHistogramArea(vector<int>&heights){
        stack<int>st;
        int max_area=0,n=heights.size();

        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>heights[i]){
                int h=heights[st.top()];
                st.pop();
                int pse_i=!st.empty()?st.top():-1;
                int w=i-pse_i-1;
                max_area=max(max_area,h*w);
            }
            st.push(i);
        }

        while(!st.empty()){
            int h=heights[st.top()];
            st.pop();
            int pse_i=!st.empty()?st.top():-1;
            int w=n-pse_i-1;
            max_area=max(max_area,h*w);
        }

        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int colms=matrix[0].size();


        int max_area=0;
        vector<int>curr_row(colms,0);

        for(int i=0;i<rows;i++){
            for(int j=0;j<colms;j++){
                if(matrix[i][j]=='1'){
                    curr_row[j]+=1;
                }
                else curr_row[j]=0;

            }

            max_area=max(max_area,computeLargestHistogramArea(curr_row));

        }

        return max_area;


    }
};
