#include<iostream>
#include <vector>
#include<cstring>
using namespace std;

string breakPalindrome(string palindrome) // it should be lexiographically the smallest
{
    string ans="";
    if (palindrome.length()==1){
        return ans;
    }
    else{
    if(palindrome[0]!='a'){
        ans='a'+palindrome.substr(1);
        return ans;
    }


        if(palindrome.length()!=3){
        if(palindrome[1]!='a'){
            ans = palindrome[0] + string("a");  // so that it treates "a" as string and concatenates correctly
            ans = ans + palindrome.substr(2);
            
        }
        else{
            ans=palindrome[0]+string("b");
            ans=ans+palindrome.substr(2);
        }
    }
        else{
            ans=palindrome.substr(0,2);
            ans=ans+string("b") ;
        }
    }
    return ans;

}


int main(){
    string input="aaa";
    cout<<breakPalindrome(input)<<endl;
}
