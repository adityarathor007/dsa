double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<pair<int,double>>unit_vals;

        for(int i=0;i<n;i++){
            double val_per_kg=(double)val[i]/wt[i];
            unit_vals.push_back({i,val_per_kg});

        }

        sort(unit_vals.begin(),unit_vals.end(),customComparator);

        double ans=0;
        for(auto p:unit_vals){
            int i=p.first;
            double val_per_kg;
            if(wt[i]<=capacity){
                capacity-=wt[i];
                ans+=val[i];
            }
            else{
                ans+=p.second*(capacity);
                break;
            }
        }

        return ans;
}
