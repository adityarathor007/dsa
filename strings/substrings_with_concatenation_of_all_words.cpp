class Solution {
    unordered_map<string,int>words_freq;
public:

    vector<int> findSubstring(string s, vector<string>& words) {
        int total_word_len=0;
        for(string word:words){
            words_freq[word]+=1;
            total_word_len+=word.size();
        }

        int n=s.size();
        vector<int>ans;

        for(int start=0;start<n-total_word_len;start++){
            string curr_word="";
            unordered_map<string,int>temp;
            temp=words_freq;
            // cout<<"sliding window s_index: "<<start<<endl;
            for(int i=0;i<total_word_len;i++){
                curr_word+=s[start+i];
                // cout<<curr_word<<endl;
                if(temp.find(curr_word)!=temp.end()){
                    temp[curr_word]-=1;
                    if(temp[curr_word]==0) temp.erase(curr_word);
                    curr_word="";
                }
            }
            if(!temp.size()) ans.push_back(start);

        }

        return ans;
    }
};
