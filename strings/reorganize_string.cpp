string reorganizeString(string s) {
        unordered_map<char,int>freq;
        int max_freq=0;
        for(char ch:s){
            freq[ch]+=1;
            max_freq=max(max_freq,freq[ch]);
        }
        string max_freq_str="";
        priority_queue<pair<int,char>>pq;

        for(auto [ch,cnt]:freq){
            if(cnt==max_freq) max_freq_str+=ch;
            else pq.push({cnt,ch});
        }

        string ans="";

        while(ans.size()!=s.size()){
            if(max_freq>0){
                ans+=max_freq_str;
                max_freq-=1;
            }
            if(!pq.empty()){
                auto [cnt,ch]=pq.top();
                pq.pop();
                ans+=ch;
                if(cnt>1) pq.push({cnt-1,ch});
            }
        }
        int n=ans.size();
        for(int i=1;i<n;i++){
            if(ans[i]==ans[i-1]) return "";
        }
        return ans;
    }
