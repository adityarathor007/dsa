#include <iostream>
#include <cstring>

using namespace std;

bool isSubstring(string s1,string s2){
    int i=s1.length()-1;
    int j=s2.length()-1;
    while(i>=0){
        if(j==-1){
            return true;
        }
        if(s1[i]==s2[j]){
            j--;
        }
        i--;
    }
    return false;

}


int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<isSubstring(s1,s2)<<endl;

return 0;
}
