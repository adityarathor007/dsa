class Solution {
    unordered_map<string,vector<char>>pattern;
    unordered_map<string, bool> memo;
public:
    bool canMake(int i,int j,vector<vector<char>>&pyramid){
        if(i==0) return true;

        string row_state = "";
        if (j == 1) {
            for (int k = 1; k <= i + 1; ++k) row_state += pyramid[i+1][k];
            if (memo.count(row_state)) return memo[row_state];
        }

        string curr_str="";
        curr_str+=pyramid[i+1][j];
        curr_str+=pyramid[i+1][j+1];
        // cout<<curr_str<<endl;

        if(pattern.find(curr_str)==pattern.end()) return false;

        for(char ch:pattern[curr_str]){
            pyramid[i][j]=ch;
            if(j==i){
                if(canMake(i-1,1,pyramid)) return true;
            }
            else {
                if(canMake(i,j+1,pyramid)) return true;
            }
        }

        pyramid[i][j]='#';
        cout<<row_state<<endl;
        if (j == 1) memo[row_state] = false;

        return false;


    }


    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n=bottom.size();
        vector<vector<char>>pyramid(n+1,vector<char>(n+1,'#'));

        for(int j=1;j<=n;j++){
            pyramid[n][j]=bottom[j-1];
        }

        for(string str:allowed){
            string key=str.substr(0,2);
            pattern[key].push_back(str[2]);
        }

        return canMake(n-1,1,pyramid);

    }
};
