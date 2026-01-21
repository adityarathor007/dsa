class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char,vector<char>>adjList;
        unordered_set<char>nodes;
        int n=words.size();

        for(int i=0;i<n-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            int m=w1.size();
            int n=w2.size();
            int len=min(m,n);
            int k=0;
            // construct graph using the differentating character
            bool found=false;
            while(k<len){
                if(w1[k]!=w2[k] and !found){
                    adjList[w1[k]].push_back(w2[k]);
                    found=true;
                }
                nodes.insert(w1[k]);
                nodes.insert(w2[k]);
                k+=1;
            }

            if(!found and m>n) return "";

            while(k<m){
                nodes.insert(w1[k]);
                k+=1;
            }

            while(k<n){
                nodes.insert(w2[k]);
                k+=1;
            }
        }

        //if just one word present in words then nothing to compare
        if(n==1){
            for(char ch:words[0]){
                nodes.insert(ch);
            }
        }

        int num_nodes=nodes.size();
        vector<int>indegree(26,0);

        for(auto [node,neighbours]:adjList){
            for(char neighbour:neighbours){
                indegree[neighbour-'a']+=1;
            }
        }


        queue<char>q;
        string ans;
        for(int i=0;i<26;i++){
            if(!indegree[i] and nodes.count(i+'a')){
                q.push(i+'a');
            }
        }


        while(!q.empty()){
            char ch=q.front();
            q.pop();
            ans+=ch;
            for(char neighbour:adjList[ch]){
                indegree[neighbour-'a']-=1;
                if(!indegree[neighbour-'a']){
                    q.push(neighbour);
                }
            }
        }

        // cout<<ans<<endl;

        if(ans.size()!=num_nodes) return "";
        return ans;


    }
};
