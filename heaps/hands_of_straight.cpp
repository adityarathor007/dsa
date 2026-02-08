bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize) return false;

        unordered_map<int,int>freq;
        sort(hand.begin(),hand.end());
        for(int num:hand) freq[num]+=1;

        int i=0;
        while(i<n){
            int curr=hand[i];
            if(!freq[hand[i]]){
                i+=1;
                continue;
            }
            freq[hand[i]]-=1;
            int j=1;
            while(j<groupSize){
                curr+=1;
                if(freq.count(curr) and freq[curr]!=0){
                    freq[curr]-=1;
                }
                else return false;
                j+=1;
            }
            i+=1;
        }
        return true;

    }
