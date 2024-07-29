class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //brute force(taking extra space)
        // int n=matrix.size();
        // int m=matrix[0].size();
        // vector<vector<int>>temp(n,vector<int>(m,0));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         temp[i][j]=matrix[j][i];
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         matrix[i][j]=temp[i][m-j-1];
        //     }
        // }

        //using O(1) space
        int n=matrix.size();
        int m=matrix[0].size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<m;j++){ //traversing just the upper half to avoid repetition
        //         swap(matrix[i][j],matrix[j][i]);  //implace transpose
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     reverse(matrix[i].begin(),matrix[i].end());
        // }

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