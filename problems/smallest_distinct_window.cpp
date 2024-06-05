#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string smallestWindow(string str)
{
    // Complete this method
    int i=0;
    int j=0;
    int start=-1;
    int max_length=0;
    unordered_map<char,int> table;

    int cc=0;

    if (str.length() == 0)
    {
        return "";
    }

    while(j<str.length()){
        char ch=str[j];

        // this last condition checks that letter has occured in the new window or not as table.count not tells about the active window
        if(table.count(ch) and table[ch]>=i ){
            // start a new window
            i = table[ch] + 1;  
            cc=j-i;
        }

        table[ch]=j;
        cc += 1;
        j++;

        if(cc>max_length){
            max_length=cc;
            start=i;

        }
        
    }
    string ans=str.substr(start,max_length);
    return ans;
}


int main(){
    string input;
    cin>>input;
    cout<<smallestWindow(input)<<endl;

}