class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //using O(1) space
        int n=matrix.size();
        int m=matrix[0].size();
    

        //for left rotate first reverse all rows then take transpose
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());

        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
};