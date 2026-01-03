class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        int n=words.size();

        for(int i=0;i<n;i++){
            vector<string>cw;
            int line_len=0;
            while(i<n and line_len+words[i].size()<=maxWidth){
                line_len+=words[i].size();
                cw.push_back(words[i]);
                line_len+=1;
                i+=1;
            }
            line_len-=1;
            i-=1;
            // cout<<i<<endl;

            string line;

            if(i!=n-1){
                int extra_space=maxWidth-line_len;
                int gaps=cw.size()-1;
                // cout<<line_len<<" "<<gaps<<endl;
                int each_div_space=0,extra_div_space=0;
                if(gaps!=0){
                    each_div_space=extra_space/gaps;
                    extra_div_space =extra_space%gaps;
                }
                // cout<<"extra space"<<endl;
                // cout<<each_div_space<<" "<<extra_div_space<<endl;

                // cout<<"starting insertion"<<endl;
                for(int j=0;j<cw.size()-1;j++){
                    line+=cw[j];
                    int c_gap=each_div_space+1;
                    if(extra_div_space){
                        c_gap+=1;
                        extra_div_space-=1;
                    }
                    for(int k=0;k<c_gap;k++) line+=' ';
                    // cout<<line.size()<<endl;
                }

                line+=cw[cw.size()-1];
                // cout<<"insertion end"<<endl;
            }
            else{
                for(string word:cw){
                    line+=word;
                    line+=' ';
                }
            }

            int cline_size=line.size();
            // cout<<"current_line size: "<<cline_size<<endl;
            if(cline_size>maxWidth) line.pop_back();

            while(cline_size<maxWidth){
                line+=' ';
                cline_size+=1;
            }

            // cout<<line<<endl;
            ans.push_back(line);
        }

        return ans;
    }
};
