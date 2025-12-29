class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        if(m>n) return false;

        unordered_map<char,int>freq_s1;

        for(char ch:s1) freq_s1[ch]+=1;

        unordered_map<char,int>curr_freq;
        for(int i=0;i<m;i++){
            curr_freq[s2[i]]+=1;
        }
        if(curr_freq==freq_s1) return true;

        for(int i=1;i<=n-m;i++){
            char prev_char=s2[i-1];
            curr_freq[prev_char]-=1;
            if(!curr_freq[prev_char]) curr_freq.erase(prev_char);
            curr_freq[s2[i+m-1]]+=1;

            // for(auto [key,value]:curr_freq){
            //     cout<<key<<": "<<value<<" ";
            // }
            cout<<endl;
            if(curr_freq==freq_s1) return true;
        }

        return false;
    }
};
