#include<iostream>
#include <vector>
#include<cstring>
using namespace std;




string normalize(const string &sentence) {
    string copy = sentence;
    for(int i=0;i<copy.length();i++){
        if (i==0){
            copy[i]=toupper(copy[i]);
        }
        else{
            if(copy[i]!=' '){
                copy[i]=tolower(copy[i]);
            }

            else{
                while(copy[i]==' '){
                    i++;
                }
                copy[i]=toupper(copy[i]);

            }
        }
    }
    //Make the changes in copy, and return it



    return copy;
}




int main(){
    string input="This is SO MUCH FUN!";
    cout<<normalize(input)<<endl;
}
