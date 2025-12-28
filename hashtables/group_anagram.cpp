vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,int>str_to_index;

        for(auto str:strs){
            string sort_str=str;
            sort(sort_str.begin(),sort_str.end());
            if(str_to_index.find(sort_str)==str_to_index.end()){
                str_to_index[sort_str]=ans.size();
                ans.push_back({str});
            }
            else{
                int index=str_to_index[sort_str];
                ans[index].push_back(str);
            }
        }


        return ans;
}
