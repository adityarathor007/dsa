#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void subsequence(string s,string o,vector <string> &v){

    //base_cond
    if(s.length()==0){
        v.push_back(o);
        return ;

    }

    // rec case
    else{
        char rem_char=s[0];
        string red_string=s.substr(1);
        // with including in output
        subsequence(red_string,o+rem_char,v);
        // with excluding in output
        subsequence(red_string,o,v);
    }
}


bool compare(string s1,string s2){
    if(s1.length()==s2.length()){
        return s1<s2;  //lexigraphic compare
    }
    return s1.length()<s2.length();  //on the basis of length
}



int main(){
    string s;
    cin>>s;
    string output="";
    vector <string> v;

    subsequence(s,output,v);
    sort(v.begin(),v.end(),compare);

    for(auto str:v){
        cout<<str<<",";
    }
    cout<<endl;
}
