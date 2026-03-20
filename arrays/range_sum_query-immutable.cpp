class NumMatrix {
    vector<vector<int>>grid;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        grid=matrix;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j) grid[i][j]+=grid[i][j-1];
            }
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]+=grid[i-1][j];
            }
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=grid[row2][col2];
        if(row1) sum-=grid[row1-1][col2];
        if(col1) sum-=grid[row2][col1-1];
        if(row1 and col1) sum+=grid[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
