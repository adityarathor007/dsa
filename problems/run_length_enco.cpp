#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

// str is the input the string
string compressString(const string &str)
{
    string ans;
    char temp = str[0];
    int counter = 1;
    for(int i=1;i<=str.length();i++){
        if(temp==str[i]){
            counter++;
        }
        else{
            ans.push_back(temp);
            ans+=to_string(counter); //concatenation of string
            counter = 1;
            temp=str[i];

        }
    }
    if(ans.length()<str.length()){
        return ans;
    }
    else{
        return str;
    }
   
    // complete the function to return output string
}

int main(){
    string text = "aaaaabc";
    cout<<compressString(text)<<endl;



    return 0;
}