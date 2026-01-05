  long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long abs_sum=0;
        int cnt_negative=0,min_abs_num=abs(matrix[0][0]);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int abs_num=abs(matrix[i][j]);
                abs_sum+=abs_num;
                min_abs_num=min(min_abs_num,abs_num);
                if(matrix[i][j]<=0) cnt_negative+=1;
            }
        }

        cout<<min_abs_num<<endl;
        if(!(cnt_negative&1)) return abs_sum;
        return abs_sum-2*min_abs_num;

    }
