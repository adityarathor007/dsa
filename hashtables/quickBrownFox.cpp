#include <climits>
#include<iostream>
#include <string>
#include <unordered_set>
using namespace std;

// string s="thequickbrownfoxjumpsoverthehighbridge";
// string words[]={"the","fox","thequickbrownfox","jumps","lazy","lazyfox","highbridge",
//     "the","over","bridge","high","tall","quick","brown"};



int min_bars_helper_func(string s,int i,unordered_set<string>&m){
    
    //base case
    if(s[i]=='\0'){
        return 0;
    }
    
    //rec case
    int ans=INT_MAX;
    string curr_string="";
    for(int j=i;s[j]!='\0';j++){
        curr_string+=s[j];
        
        //at every step check if this prefix is present inside the set or not
       if(m.find(curr_string)!=m.end()) {

           int remaining_ans=min_bars_helper_func(s, j+1, m);
           if(remaining_ans!=-1){
               
               ans=min(ans,remaining_ans+1);
               
           }
       }
    }
    
    if(ans==INT_MAX){ //means no parition available
        return -1;
        
    }
    return ans;
    
}


int min_bars(string s, string words[], int n){

    unordered_set<string> m;
    for(int i=0; i<n; i++){
        m.insert(words[i]);
    }
    int idx=0;
    int output=min_bars_helper_func(s,idx,m);
    return output-1;
    
}

int main(){
    string s="thequickbrownfox";
    string words[] ={"the", "quickbrown","quick","brown","fox"};
    int n=sizeof(words)/sizeof(words[0]);
    cout<<min_bars(s,words,n)<<endl;
    return 0;
}