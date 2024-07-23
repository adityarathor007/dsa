#include<bits/stdc++.h>
using namespace std;


pair<char,int> helperFunc(string s,int st,int en){
    // if(st==en){
    //     return {s[st],1};
    // }
    // if(ch%2==0){
    //     if(s[st]=='H' and s[en]=='H'){
    //         return {'H',0};
    //     }
    //     auto opt1=helperFunc(s,st+1,en,ch+1);
    //     auto opt2=helperFunc(s,st,en-1,ch+1);
    //     return {'O',max(opt1.second,opt2.second)};
        
    // }
    // else{
    //     if(s[st]=='O' and s[en]=='O'){
    //         return {'O',0};
    //     }
    //     auto opt1=helperFunc(s,st+1,en,ch+1);
    //     auto opt2=helperFunc(s,st,en-1,ch+1);
    //     return {'T',max(opt1.second,opt2.second)}; 
    // }
    
}



pair<char,int> GameOfWits(string s){
    //Write your code here. Do not modify the function or parameters. Use a helper function if needed.
    int n=s.length();
    return helperFunc(s,0,n-1,0);
}

int main(){
    string s="HOOOOHHO";
    auto pair=GameOfWits(s);
    cout<<pair.first<<" "<<pair.second<<endl;
}