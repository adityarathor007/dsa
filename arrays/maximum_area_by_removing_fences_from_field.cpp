unordered_set<int>findSides(vector<int>&Fences){
        unordered_set<int>sides;
        int n=Fences.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sides.insert(Fences[j]-Fences[i]);
            }
        }
        return sides;
    }

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        if(n==m) return (n-1)*(n-1);
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_set<int>hSides=findSides(hFences);
        unordered_set<int>vSides=findSides(vFences);

        int max_common_side=0;
        for(auto hside:hSides){
            if(vSides.count(hside)) max_common_side=max(max_common_side,hside);
        }

        long long area=(long long )max_common_side*max_common_side;
        if(area==0) return -1;
        int MOD=1e9+7;
        return area%MOD;

    }
