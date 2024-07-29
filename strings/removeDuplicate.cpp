#include<iostream>
#include<vector>
using namespace std;

string removeDuplicate(string str){
    //T_C=O(n) and S_C=O(n)
    //   string ans;
    //     unordered_map<char,int>m;
    //     int n=str.length();
    //     for(int i=0;i<n;i++){
    //         if(m.find(str[i])==m.end()){
    //             ans.push_back(str[i]);
    //             m[str[i]]=i;
    //         }
    //     }
       
        
    //     return ans;

    // T_C=O(n) and S_C=O(1) as using fixed size array
    vector<int>chars(255,0);
    int n=str.length();
    string ans;
    for(int i=0;i<n;i++){
        int ascii=str[i];
        if(chars[ascii]==0){
            chars[ascii]+=1;
            ans.push_back(str[i]);
        }
    }

    return ans;



    }




int main(){
    string str="gfg";
    cout<<removeDuplicate(str)<<endl;
}