#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1,string s2){
    // make cases and reject them and accept them
//     if(s1.length()==s2.length()){
//         return s1>s2;
//     }
  
//     if(s2.length()>s1.length()){
//         string s2_mod = s2.substr(0, s1.length());
//         if(s2_mod!=s1){
//             return s1 > s2_mod;
//         }
//         else{
//             return s1<s2;  //this will help in rejecting 202 and accepting 220
//         }
        
//     }
//     else{
//         string s1_mod=s1.substr(0,s2.length());
//         if(s1_mod!=s1){
//             return s1_mod > s2;
//         }
//         else{
//             return s1>s2;
//         }
        
//     }
    

// alternative approach(easier)
return s1+s2>s2+s1;

}





string concatenate(vector<int> numbers)
{
    // complete this method and return the largest number you can form as a string
    vector <string> ans;
    string temp;
    for(int x:numbers){
       temp=to_string(x);
       ans.push_back(temp);

    }

    sort(ans.begin(),ans.end(),compare);
    string out=ans[0];
    for(int i=1;i<ans.size();i++){
        out=out+ans[i];
    }
    return out;


}


int main(){
    vector<int> numbers = {10, 11, 20, 30, 2};
    string s=concatenate(numbers);
    cout<<s<<endl;
}