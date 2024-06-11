#include <climits>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//subsets=substring != subsequence
//for abc ac is the substring but not subsequence


void findingSubsets(string input,int index=-1,string curr=""){
    int n=input.length();
    if(input.length()==index){
        cout<<curr<<",";
        return ;
    }
    findingSubsets(input,index+1,curr+input[index]);  //index represents the current position of character to be considered for  recursion
    findingSubsets(input,index+1,curr);
}

int main(){
    string input;
    cin>>input;
    findingSubsets(input);
}