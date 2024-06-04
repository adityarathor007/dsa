#include<iostream>
#include<unordered_map>
using namespace std;

string unique_longest_substring(string input){
    int i=0;
    int j=0;
    unordered_map<char, int>table;
    pair<int,string> temp;

    
    int longest_length=0;
    int cc=0;
    int start=-1;
    
    
    while(j<input.length()){
        char ch=input[j]      ;
        
        // if it is inside hashmap and its idx >= start_idx
        if(table.count(ch) and table[ch]>=i){
            //start a new window
            i=table[ch]+1;
            cc=j-i; //updated window_length excluding the incoming character as it is getting added in the next step
        }
        
        // update the last occ
        table[ch]=j;
        cc+=1;
        j++;
        
        if(cc>longest_length){
            longest_length=cc;
            start=i;
        }
       
    }
    string ans=input.substr(start,longest_length);
    
    return ans;
    
}




int main(){
    
    string input;
    cin>>input;
    
    cout<<unique_longest_substring(input)<<endl;
    
    
    return 0;
}