
int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int str_len=strs[0].size();

        int cnt=0;
        unordered_set<int>rows_to_check;
        for(int i=1;i<n;i++) rows_to_check.insert(i);

        for(int j=0;j<str_len;j++){
            int prev_cnt=cnt;
            unordered_set<int>next_rows_to_check;
            bool check=true;
            for(int i:rows_to_check){
                if(strs[i][j]<strs[i-1][j]){
                    check=false;
                }
                if(strs[i][j]==strs[i-1][j]) next_rows_to_check.insert(i);
            }

            if(!check){
                cnt+=1;
                continue; //not updating the ones which worked as with the removal of this colm the ones which worked will also become invalid
            }
            if(!next_rows_to_check.size())  return cnt;
            rows_to_check=next_rows_to_check; //updating the next rows which need to be checked as their curr and curr-1 string have the same character
        }
        return cnt;
};
