#include <bits/stdc++.h>
using namespace std;


string breakPalindrome(string palindrome) // it should be lexiographically the smallest
{   
    string ans="";
    if (palindrome.length()==1){
        return ans;
    }
    if(palindrome[0]!='a'){
        ans='a'+palindrome.substr(1);
        return ans;
    }
    else{
        

        if(palindrome[1]!='a'){
            ans = palindrome[0] + string("a");  // so that it treates "a" as string and concatenates correctly
            ans = ans + palindrome.substr(2);
            return ans;
        }
        else{
            ans=palindrome[0]+string("b");
            ans=ans+palindrome.substr(2);
        }
    }
    
}


int main(){
    string input="aaa";
    cout<<breakPalindrome(input)<<endl;
}