#include <climits>
#include <iostream>
#include<unordered_map>
using namespace std;


unordered_map<char, int> find_map(string ss){
    int i=0;
    unordered_map<char, int> ans;
  
    while(i<ss.length()){
        char ch=ss[i];
        if(ans.count(ch)){
            ans[ch]+=1;
        }
        else{
            // first time insertion
            ans[ch]=1;
        }
        i++;
    }
    
    return ans;
}

string find_string_wind(string bs,unordered_map<char, int> table,string ss){
    int j=0;
    int i=0;
    int min_len=INT_MAX;
    int cc=0;
    int start=-1;
    
    int matched_char=0;
    unordered_map<char, int> temp;
    while(j<bs.length()){
        char ch=bs[j];
        if(temp.count(ch)){
            temp[ch]+=1;
        }
        else{
            temp[ch]=1;
        }
        
        //check if temp matches with table map or not
        //to check how it matches we count how many characters have been matched untill now;
        if(table[ch]!=0 and temp[ch]<=table[ch]){
            matched_char+=1;
        }
        
        if(matched_char==ss.length()){
              //if it matches then we contract the window by removing unwanted character(1.np in ss 2. freq is higher in bs )
              while(ss[i]==0 or bs[i]>ss[i]){
                  bs[i]--;
                  i++;
              }
              cc=j-i+1;
              if(cc<min_len){
                  min_len=cc;
                  start=i;
              }
              
              
        }
        
        
      
        
        //else we continue in the loop
        j++;
    }
    if(start==-1){
        return "No window found";
    }
    return bs.substr(start,min_len);
}


int main(){
    
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    unordered_map<char, int>table;
    table = find_map(s2);
    // for (auto i = table.begin(); i != table.end(); i++) 
    //         cout << i->first << " " << i->second << endl; 
    
    cout<<find_string_wind(s1,table,s2)<<endl;
    
    
}