void setZeroes(vector<vector<int>>& matrix) {
    unordered_map<int>rows;
    unordered_map<int>cols;
    int m=matrix.size();
    int n=matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                if(rows.find(i)==rows.end()){
                    rows.insert(i);
                }
                if(cols.find(j)==cols.end()){
                    cols.insert(j);
                }

            }
        }
    }


    // setting the rows and cols to zero
    for(auto x:rows){
        for(int j=0;j<n;j++){
            matrix[x][j]=0;
        }
    }

    for(auto x:cols){
        for(int i=0;i<n;i++){
            matrix[i][x]=0;
        }
    }

}
