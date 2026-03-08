unordered_map<int,int>rows;
unordered_map<int,int>colms;
unordered_map<int,int>diag;
unordered_map<int,int>anti_diag;
set<pair<int,int>>lampSet;
vector<vector<int>>dirn{{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};

void f(int x,int y,int op){
    rows[x]+=op;
    if(rows[x]==0) rows.erase(x);
    colms[y]+=op;
    if(colms[y]==0) colms.erase(y);
    diag[x-y]+=op;
    if(diag[x-y]==0) diag.erase(x-y);
    anti_diag[x+y]+=op;
    if(anti_diag[x+y]==0) anti_diag.erase(x+y);
}

bool isValid(int x,int y,int n){
    if(x>=0 and y>=0 and x<n and y<n) return true;
    return false;
}

bool checkOn(int x,int y){
    return rows.count(x) or colms.count(y) or diag.count(x-y) or anti_diag.count(x+y);
}


void turnOff(int x,int y,int n){
    if(lampSet.count({x,y})){
        f(x,y,-1);
        lampSet.erase({x,y});
    }
    for(int k=0;k<8;k++){
        int nx=x+dirn[k][0];
        int ny=y+dirn[k][1];
        if(isValid(nx,ny,n) and lampSet.count({nx,ny})){
            f(nx,ny,-1);
            lampSet.erase({nx,ny});
        }
    }

}

vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    lampSet.clear();
    rows.clear();
    colms.clear();
    diag.clear();
    anti_diag.clear();

    for(auto lamp:lamps){
        if(!lampSet.count({lamp[0],lamp[1]})){
            f(lamp[0],lamp[1],1);
            lampSet.insert({lamp[0],lamp[1]});
        }
    }


    vector<int>ans;
    for(auto query:queries){
        int x=query[0],y=query[1];
        ans.push_back(checkOn(x,y));
        turnOff(x,y,n);
    }
    return ans;
}
