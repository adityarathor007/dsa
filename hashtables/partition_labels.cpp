vector<int> partitionLabels(string s) {
      unordered_map<char,int>max_index;
      int n=s.size();
      for(int i=0;i<n;i++){
        max_index[s[i]]=i;
      }
      vector<int>ans;
      int cmax_index=0;
      int start_index=0;

      for(int i=0;i<n;i++){
        char ch=s[i];
        cmax_index=max(cmax_index,max_index[ch]);
        if(i==cmax_index){
            ans.push_back(i-start_index+1);
            start_index=i+1;
        }
      }
      return ans;

    }
