#include<iostream>
using namespace std;

string urlify(string &s,int n){
    // int n=s.length();

    int i=0;
    string temp=s;
    int j=0;
    while(i<n){
        if(s[i] ==' '){
            temp[j]='%';
            j++;
            temp[j]='2';
            j++;
            temp[j]='0';
            j++;
            
        }
        else{
            temp[j] = s[i];
            j++;
        }
        

        i++;
       
    }
    // cout<<j<<endl; this j will point to the last index of the input string as it contains sufficient space to accomadate
    return temp;
}

int main(){
    string input="Mr John Smith    ";
    int n; //the lenght of the string that contains word
    cin>>n;


    cout<<urlify(input,n)<<endl;
    
    return 0;
}