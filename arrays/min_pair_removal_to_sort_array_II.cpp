class Solution {
        unordered_map<int,long long>values;
        unordered_map<int,int>prev;
        unordered_map<int,int>next;
        set<pair<long long,int>>pairSum;
        int flipped;
public:
    void add(int i,int n){
        if(i>=0 and i<n){
            int j=next[i];
            if(j<n){
                pairSum.insert({values[i]+values[j],i});
                if(values[i]>values[j]) flipped++;
            }
        }
    }

    void remove(int i,int n){
        if(i>=0 and i<n){
            int j=next[i];
            if(j<n){
                auto it=pairSum.find({values[i]+values[j],i});
                if(it!=pairSum.end()){
                    if(values[i]>values[j]) flipped--;  //as this pair is removed
                    pairSum.erase(it);
                }
            }
        }

    }
    int minimumPairRemoval(vector<int>& nums) {
        values.clear();prev.clear();next.clear();
        pairSum.clear();

        int n=nums.size();
        if(n<2) return 0;

        for(int i=0;i<n;i++){
            values[i]=nums[i];
            prev[i]=i-1;
            next[i]=i+1;
        }

        flipped=0;

        for(int i=0;i<n-1;i++){
            if(values[i]>values[i+1]) flipped+=1;
            pairSum.insert({values[i]+values[i+1],i});

        }


        int operations=0;
        while(flipped>0){
            auto it=pairSum.begin();
            int left_i=it->second;
            pairSum.erase(it); //remove the sum of left_i and right_i

            int right_i=next[left_i];
            int prev_i=prev[left_i];
            int next_i=next[right_i];

            remove(prev_i,n);  //remove the sum of prev_i and left_i
            if(values[left_i]>values[right_i]) flipped--;
            remove(right_i,n); //remove the sum of right_i and next_i

            values[left_i]+=values[right_i];
            operations++;

            // updating the next of left_i and prev of next_i
            next[left_i]=next_i;
            if(next_i<n) prev[next_i]=left_i;

            add(prev_i,n); //add the sum of prev_i and (left_i,right_i)
            add(left_i,n); //add the sum of (left_i,right_i) and next_i

        }

        return operations;

    }
};
