#include <iostream>
using namespace std;

string convertToBin(int n){
    string ans;
    while(n>=1){
       
        if(n%2==1){
            ans.append("1");
        }
        else{
            ans.append("0");
        }
        n=n/2;
    }
    return ans;
}



int main(){
    int n;
    cin>>n;
    cout<<convertToBin(n)<<endl;
}