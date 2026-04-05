class Solution {
    vector<int>parent,rank;
    unordered_map<int,int>primeMap;
    unordered_map<int,unordered_set<int>>factors_mp;
    vector<int> spf;
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

    void sieve(){
        spf.resize(100001,1);
        spf[0]=spf[1]=1;
        for(int i=2;i<=100000;i++){
            if(spf[i]==1){ //not yet marked
                spf[i]=i;   // Mark prime numbers with themselves
                for(int j=i;j<=100000;j+=i){
                    if(spf[j]==1){
                        spf[j]=i;
                    }
                }
            }
        }
    }

    void addPrimeNumber(int num){
        vector<int>factors;
        int temp=num;
        while(temp!=1){
            int pf=spf[temp];
            if(!primeMap.count(pf)){
                int ind=primeMap.size();
                primeMap[pf]=ind;
            }
            factors.push_back(pf);
            temp /= spf[temp];
        }

        for(int factor:factors){
            factors_mp[num].insert(factor);
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums[0]==1 and nums.size()==1) return true;
        sieve();
        for(int num:nums){
            if(num==1) return false; //as this wont connect with anyone
            // cout<<"start: "<<num<<endl;
            addPrimeNumber(num);
        }
        // for(auto [num,ind]:primeMap){
            // cout<<num<<" "<<ind<<endl;
        // }

        int n=primeMap.size();
        if(!n) return false;

        parent.assign(n,0);
        rank.assign(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }



        for(auto [key,st]:factors_mp){
            auto prev = st.end();
            // cout<<"start: "<<key<<endl;
            for (auto curr = st.begin(); curr != st.end(); ++curr) {
                if (prev != st.end()) {
                    int i1=primeMap[*prev];
                    int i2=primeMap[*curr];
                    unionByRank(i1,i2);
                }
                prev = curr; // Move prev forward
                // cout<<*curr<<" ";
            }
            // cout<<endl;
        }

        bool found=false;

        for(int i=0;i<n;i++){
            if(findParent(i)==i){
                if(!found) found=true;
                else return false;
            }
        }

        return true;
    }
};
