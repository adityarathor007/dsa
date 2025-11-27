class Solution {
public:
    string mergeStrings(vector<string>&cws){
        string mergeStrings="";
        for(string word:cws){
            mergeStrings+=word;
            mergeStrings+=" ";
        }
        mergeStrings.pop_back();
        // cout<<"MergedString: "<<mergeStrings<<endl;
        return mergeStrings;
    }

    string mergeStrings_wo_padding(vector<string>&cws,int cs,int maxWidth){
        // cout<<"hello"<<endl;
        string mergeStrings="";
        for(string word:cws){
            mergeStrings+=word;
            mergeStrings+=" ";
        }
        mergeStrings.pop_back();
        int extra_padding=maxWidth-cs+1;
        mergeStrings.append(extra_padding,' ');
        return mergeStrings;
    }

    string mergeWithEqualPadding(vector<string>cws,int cs,int maxWidth){
        string mergeStrings="";
        // cout<<cs<<" "<<maxWidth<<endl;
        int padding_req = maxWidth-cs+1; //last word remove its padding which is added in count
        if(cws.size()==1){
            mergeStrings+=cws[0];
            mergeStrings.append(padding_req, ' ');
            return mergeStrings;
        }
        int min_padding = padding_req/(cws.size()-1); //after last word no padding
        int extra_padding = padding_req%(cws.size()-1);
        // cout<<"min_padding: "<<min_padding<<"extra_padding: "<<extra_padding<<endl;

        int i=0;
        for(i=0;i<cws.size()-1;i++){
            mergeStrings+=cws[i];
            mergeStrings.append(min_padding+1, ' ');
            if(extra_padding!=0){
                mergeStrings+=' ';
                extra_padding-=1;
            }
        }
        mergeStrings+=cws[i];
        // cout<<"MergedString: "<<mergeStrings<<endl;
        return mergeStrings;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        vector<string>cws;
        int cs=0;

        for(string word:words){
            // cout<<word<<endl;
            cs+=word.size()+1; //including the blank space
            // cout<<cs<<endl;
            if(cs-1<maxWidth){
                cws.push_back(word);
            }
            else if(cs-1==maxWidth){
                cws.push_back(word);
                ans.push_back(mergeStrings(cws));
                cws.clear();
                cs=0;
            }
            else{
                cs-=word.size()+1;
                ans.push_back(mergeWithEqualPadding(cws,cs,maxWidth));
                cws.clear();
                cws.push_back(word);
                cs=word.size()+1;
            }
        }

        // 0 possible that all words were inserted when the cs-1 was == maxWidth
        if(cws.size()!=0){
            ans.push_back(mergeStrings_wo_padding(cws,cs,maxWidth));
        }


        // ans.push_back(mergeStrings(cws));
        return ans;
    }
};
