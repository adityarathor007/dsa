#include <iostream>
#include <stack>
using namespace std;

bool checkRedundant(string input){
    stack<char> s;
    
    for(auto ch:input){
        if(ch!=')'){
            s.push(ch);  // a + b * (
        }
        else{  // if encounter ')'
                
            bool operator_found=false;
            
            while(!s.empty() and s.top()!='('){
                char top=s.top();
                if(top=='+' or top=='-' or top=='*' or top=='/'){
                    operator_found=true;
                }
                s.pop();
            }
            s.pop();  //poping the bracket after the loop is over
            if (!operator_found){
                return true;
            }
        }
    }
    return false;
}


int main(){
    //given that parenthesis are '(' and ')' also the parenthesis are balanced
    string s="((a+b)+c)+((d)+e)";
    if(checkRedundant(s)){
        cout<<"redundant parenthesis"<<endl;
    }
    else{
        cout<<"no redundant parenthesis"<<endl;
    }
}