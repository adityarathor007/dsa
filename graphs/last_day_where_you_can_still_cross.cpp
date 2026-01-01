class DisjointSet{
public:
    vector<int>parent,rank;

    DisjointSet(int n){
        parent.assign(n,0);
        rank.assign(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUltimateParent(int n){

        if(parent[n]==n) return n;
        return parent[n]=findUltimateParent(parent[n]);
    }

    void unionByRank(int n1, int n2){
        int up1=findUltimateParent(n1);
        int up2=findUltimateParent(n2);
        if(up1==up2) return;
        if(rank[up1]<rank[up2]) swap(up1,up2);
        parent[up2]=up1;
        if(rank[up1]==rank[up2]) rank[up1]+=1;
    }

};


class Solution {
public:
    vector<vector<int>>dirn{{-1,0},{0,1},{1,0},{0,-1}};

    bool isValid(int i,int j,int row,int col){
        if(i>=0 and i<row and j>=0 and j<col) return true;
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int n=row*col;
        DisjointSet ds=DisjointSet(n+2);  //2 virtual nodes to represent the entire upper row and bottom row
        vector<vector<int>>grid(n,1);

        //Assume at the starting it is all water we need to find when is the time when the land at the start connect with the bottom which is the last time we can reach from top to bottom because t+1 to that you cant reach bottom
        for(int i=cells.size()-1;i>=0;i--){ //we traverse in the opposite direction
            int x=cell[0]-1,y=cell[1]-1;
            int n1=col*x+y+1;

            grid[x][y]=0; //converting to land

            for(int k=0;k<4;k++){
                int nx=x+dirn[k][0];
                int ny=y+dirn[k][1];
                if(isValid(nx,ny,row,col) and grid[nx][ny]==0){
                    int n2=col*nx+ny+1;
                    ds.unionByRank(n1,n2); //connecting if neighbors are land
                }
            }

            if(x==0) ds.unionByRank(0,n1);
            if(x==rows-1) ds.unionByRank(n+1,n1);
            if(ds.findUltimateParent(0)==ds.findUltimateParent(n+1)) return i;

        }
        return -1;

    }
};
