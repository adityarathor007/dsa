
// You are given an m x n binary matrix grid.

// A row or column is considered palindromic if its values read the same forward and backward.

// You can flip any number of cells in grid from 0 to 1, or from 1 to 0.

// Return the minimum number of cells that need to be flipped to make all rows and columns palindromic, and the total number of 1's in grid divisible by 4.

 
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int op=0;
    
        for(int i=0;i<m/2;i++){
            for(int j=0;j<n/2;j++){
                int u=grid[i][j];
                int v=grid[i][n-j-1];
                int w=grid[m-i-1][j];
                int z=grid[m-i-1][n-j-1];
                int ones=u+v+w+z;
                if(ones<=2) op+=ones; //making a multiple of 4 by deciding taking the corresponding pieces of the rows and column and finding the min opertion of bit flip to make a pallindrome and a multiple of 4
                else op+=(4-ones);

            }

        }

        int c=0;  //the number of bitflip operations if it does not matches and in this we have both options of conversion to 1 and conversion to 0
        int c2=0;  
        if(m%2){
            for(int j=0;j<n/2;j++){
                if(grid[m/2][j]!=grid[m/2][n-j-1]){
                    c+=1;
                }
                else if(grid[m/2][j]) c2+=1;
            }
        }


        if(n%2){
            for(int i=0;i<m/2;i++){
                if(grid[i][n/2]!=grid[m-i-1][n/2]){
                    c+=1;
                }
                else if(grid[i][n/2]) c2+=1;
            }
        }

        if(c2%2 and c==0) c+=2;  //if c2%2 is odd it means the ones are not multiple of 4 but are in multiple of 2 and if c==0 means that there is nothing to support its conversion to multiple of 4 but if c!=0 that means the mismatch bits can be converted such that it becomes multiple of 4
        if(n%2 and m%2) c+=grid[m/2][n/2]; //for middle most element which does not gets considered in any case 

        return op+c;
        

    }
};