#include <climits>
#include<iostream>
#include<vector>
using namespace std;

// we need to add rules so as to avoid some branches
// Rule 1 close<open 
// Rule 2 open<N
void generateBracket(string output, int n,int open,int close,int i){
    //basecase
    if(i==2*n){
        cout<<output<<endl;
        return ;
    }
    
    //open 
    if(open<n){
        // output+='(';//this is wrong as 
        // generateBracket(output,  n, open+1,  close, i+1);// in the function with no bracket we add ( and in then ) which is wrong as 
        // in this function the output was with no bracket we are in the next if we already have with ) in output instead it should be output bracket
        generateBracket(output+'(',  n, open+1,  close, i+1);//

    }
    //closing
    if(close<open){
        generateBracket(output+')',  n,  open,  close+1, i+1);
    }
}

int main(){
    string output;
    int n;
    cin>>n;
    generateBracket(output,n,0,0,0);
}