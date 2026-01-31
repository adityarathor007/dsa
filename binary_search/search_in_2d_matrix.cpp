 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int row=0,colm=n-1;
        while(row<m and colm>=0){
            int curr=matrix[row][colm];
            if(curr==target) return true;
            if(curr<target) row+=1;
            else colm-=1;
        }

        return false;
    }
