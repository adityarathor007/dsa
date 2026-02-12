void recGenerate(int o,int c,string cs,int n,vector<string>&ans){
        if(o==n and o==c){
            ans.push_back(cs);
            return;
        }

        if(o<n) recGenerate(o+1,c,cs+'(',n,ans);
        if(c<o) recGenerate(o,c+1,cs+')',n,ans);
        return;

}

vector<string> generateParenthesis(int n) {
    vector<string>ans;
    string cs="";
    recGenerate(0,0,cs,n,ans);
    return ans;
}
