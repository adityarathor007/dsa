   vector<int>parent,rank;
public:
    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u]=findParent(parent[u]);
    }

    void unionByRank(int u,int v){
        int up=findParent(u);
        int vp=findParent(v);
        if(up==vp) return;
        if(rank[up]<rank[vp]) swap(up,vp);
        parent[vp]=up;
        if(rank[up]==rank[vp]) rank[up]+=1;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        rank.assign(n,0);
        parent.assign(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(lcp[i][j]>n-j) return ""; //cant have more char common then the len of n-j;
                if(j<i){
                    if(lcp[i][j]!=lcp[j][i]) return "";
                }
                else if(i==j){
                    if(lcp[i][i]!=n-i) return "";
                }
                else{
                    if(lcp[i][j]) unionByRank(i,j);  //if has more than one character common then their first character will be equal
                }
            }
        }

        map<int,vector<int>>cntd_grps;
        for(int i=0;i<n;i++){
            int up=findParent(i);
            cntd_grps[up].push_back(i);
        }

        if(cntd_grps.size()>26) return ""; //require more than alphabetical character


        // start with a then further characters to other grps to get the lexicographically smallest one
        string ans(n,'#');
        char ch='a';
        for(auto [key,vec]:cntd_grps){
            for(int ind:vec){
                ans[ind]=ch;
            }
            ch+=1;
        }

        // cout<<ans<<endl;

        // verifying the cnts (entire prefix constraints should hold)
        vector<vector<int>>myLCP(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(ans[i]==ans[j]){
                    if(i<n-1 and j<n-1){
                        myLCP[i][j]=1+myLCP[i+1][j+1];
                    }
                    else myLCP[i][j]=1;
                }
            }
        }


        // cout<<ans<<endl;
        if(myLCP!=lcp) return "";

        return ans;
    }
