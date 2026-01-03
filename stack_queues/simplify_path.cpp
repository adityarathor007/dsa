class Solution {
public:
    string simplifyPath(string path) {
        string ans="/";
        int n=path.size();
        deque<string>dirs;

        for(int i=1;i<n;i++){
            if(path[i]=='/') continue;
            string curr_dir="";
            while(i<n and path[i]!='/'){
                curr_dir+=path[i];
                i+=1;
            }
            i-=1;
            // cout<<curr_dir<<endl;
            if(curr_dir==".") continue;
            else if(curr_dir==".."){
                if(!dirs.empty()) dirs.pop_back();
            }
            else dirs.push_back(curr_dir);

        }

        while(!dirs.empty()){
            ans+=dirs.front();
            dirs.pop_front();
            ans+='/';
        }

        if(ans.size()>1) ans.pop_back();
        return ans;
    }
};
