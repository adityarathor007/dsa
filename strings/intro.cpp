#include<iostream>
#include<string>
#include <vector>
using namespace std;

int main(){

    // char a[1000]={'1','a','c','d'}  not usefull as size has to be specified before
    
    // string s; //Dynamic Array

    // getline(cin,s,'.');  //take input from the user and delimter is '.'

    
    // // to print each character
    // for(char c:s){
    //     cout<<c<<",";
    // }


    // cout<<endl;

    // cout<<s<<endl;


    //---------- Creating vector of strings----------

    int n=5; // numbers of string taken as input
    vector<string> sarr;
    string temp;

    while(n--){
        getline(cin,temp);
        sarr.push_back(temp);
    }
    
    for(string s:sarr){
        cout<<s<<","<<endl;
    }

}
