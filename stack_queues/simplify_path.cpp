class Solution {
public:
    int findDotSize(int i, string& path){
        int j=i;
        int n=path.size();
        while(j!=n){
            if(path[j]=='/') break;
            j+=1;
        }
        return j-i;
    }

    string simplifyPath(string path) {
        int n=path.size();

        deque<string>dq;
        for(int i=0;i<n;i++){
            if(path[i]=='.'){
                    int dot_size=findDotSize(i,path);
                    if(dot_size==1){
                        continue;
                    }
                    else if(dot_size==2 and path[i+1]=='.'){
                        if(!dq.empty()) dq.pop_back();
                    }
                    else{
                        string curr_dir="";
                        while(i!=n and path[i]!='/'){
                            curr_dir+=path[i];
                            i+=1;
                        }
                        dq.push_back(curr_dir);

                    }

                }
            else if(path[i]!='/'){
                string curr_dir="";
                while(i!=n and path[i]!='/'){
                    curr_dir+=path[i];
                    i+=1;
                }
                // cout<<curr_dir<<endl;
                if(curr_dir!="") dq.push_back(curr_dir);
            }
        }

        string ans="/";
        while(!dq.empty()){
            ans+=dq.front();
            dq.pop_front();
            if(!dq.empty())ans+='/';
        }
        return ans;

    }
};
