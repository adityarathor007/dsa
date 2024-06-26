#include<iostream>
#include <unordered_set>
using namespace std;


char firstRepeatChar(string input){
    unordered_set<char> table;

    
    for(auto ch:input){
        if(table.find(ch)!=table.end()){
            return ch;
        }
    table.insert(ch);
    }
    return '\0';
    
    
}


int main(){
    string in="codingminutes";
    cout<<firstRepeatChar(in)<<endl;
}