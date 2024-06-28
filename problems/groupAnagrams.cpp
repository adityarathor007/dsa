#include<iostream>
#include<map>
using namespace std;

vector<int> computeHash(string s){
    vector<int>hash(26,0);
    for(int i=0;i<s.length();i++){
        hash[s[i]-'a']++;
    }
    return hash;
}


vector<vector<string> > groupAnagrams(vector<string> strs){
    //Write your code here. Do not modify the function or the parameters. 
    map<vector<int>,vector<string> > m;
    
    for(int i=0;i<strs.size();i++){
        vector<int> hash=computeHash(strs[i]);
        m[hash].push_back(strs[i]);
        
    }
    vector<vector<string> > ans;
    for(auto vec:m){
       ans.push_back(vec.second);
    }
    
    return ans;
}

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
       vector<vector<string>> result = groupAnagrams(strs);
       
       for (const auto& group : result) {
           for (const auto& str : group) {
               cout << str << " ";
           }
           cout << endl;
       }
       
       return 0;
   }
