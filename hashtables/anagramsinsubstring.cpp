#include<iostream>
#include <string>
#include <map>
using namespace std;


//Generate all the substrings
//Generate their hash
//Club all strings with same hash in a single window and get the freq count
//then nC2 is number of pairs with a particular hash value where n has to be greater than 1

vector<int> getHashValue(string s,int i,int j){
    
    vector<int> freq_ch(26,0);
    for(int k=i;k<=j;k++){
        char ch=s[k];
        freq_ch[ch-'a']++;
    }
    
    return freq_ch;
    
    
}



int anagrams_substring(string s){
    
    map <vector<int>,int > m;
        vector<int> h;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                    h=getHashValue(s,i,j);
                    m[h]++;
            }
        }
    
    int ans=0;
    for(auto p:m){
        int freq=p.second;
        if(freq>=2){
            ans+=(freq*(freq-1))/2;
        }
    }
    return ans;
}


int main(){
    string input;
    cin>>input;
    cout<<anagrams_substring(input)<<endl;
}