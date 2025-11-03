int countCitations(int prob_h,vector<int>&citations){
        //number of papers with atleast prob_h citations
        auto it=lower_bound(citations.begin(),citations.end(),prob_h);
        int index=distance(citations.begin(), it);
        int cnt=citations.size()-index;
        // cout<<prob_h<<" "<<cnt<<endl;
        return cnt;
    }

    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int l=0,r=0;
        for(int num:citations){
            // l=min(num,l);
            r=max(num,r);
        }

        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2; //probable_citations
            if(countCitations(mid,citations)>=mid){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
