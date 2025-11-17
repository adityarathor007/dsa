vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();
        int top=0,left=0,right=n-1,bottom=m-1;
        vector<int>ans;

        while(top<=bottom and left<=right){

            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }

            top+=1;


            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right-=1;


            if(top>bottom or left>right) break;  //either of it went ahead then all elements are covered

            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }

            bottom-=1;


            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left+=1;
        }

        return ans;
    }
