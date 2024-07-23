#include<bits/stdc++.h>
using namespace std;


bool checkPalindrome(string s,int i,int n){
    //base case
    if(i>=n/2){
        return true;
    }
    if(s[i]!=s[n-i-1]){
        return false;
    }
    return checkPalindrome(s,i+1,n);

}

int main(){
    string s;
    cin>>s;
    int n=s.length();
    if(checkPalindrome(s,0,n)){
        cout<<"It is a palindrome"<<endl;
    }
    else{
        cout<<"Not a palindrome"<<endl;
    }

}