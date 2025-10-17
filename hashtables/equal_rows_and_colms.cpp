struct VecHash {
    size_t operator()(const vector<int>& v) const noexcept {
        // Simple but effective hash combiner
        size_t h = 0;
        for (int x : v) {
            h ^= std::hash<int>{}(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

     //brute force solution(O(n^3))
    //   int cnt=0;
    //   int n=grid.size();
    //   for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         vector<int>curr_colm;
    //         for(int row=0;row<n;row++){
    //             curr_colm.push_back(grid[row][j]);
    //         }
    //         if(curr_colm==grid[i]) cnt+=1;
    //     }
    //   }
    //   return cnt;


    //using unordered_map with custom hash function to store the vectors in it
    unordered_map<vector<int>,int,VecHash>rows;
    int n=grid.size();
    for(int i=0;i<n;i++){
        rows[grid[i]]+=1;
    }

    int cnt=0;
    vector<int>colm(n);
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            colm[i]=grid[i][j];
        }
        cnt+=rows[colm];
    }

    return cnt;


    }
};
