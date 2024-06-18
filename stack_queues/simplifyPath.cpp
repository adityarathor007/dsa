#include<iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

string simplifyPath(string path){
    
    
    //step-1 tokenisation and filtering
    istringstream iss(path);
    string token;
    vector <string> tokens;; 
    while(getline(iss,token,'/')){
        if(token=="" or token=="."){
            continue;
        }
        tokens.push_back(token);
        
    }
    
    // for(auto x:tokens){
    //     cout<<x<<endl;
    // }
    
    
    //step-2 handle 
    vector<string> stack;
    if(path[0]=='/'){
        stack.push_back("");  //wrt to root dir to indicate the path is a absolute not relative as in relative we have ../../ which have significace but not in /../.
    }
    
    for(string token:tokens){
        if(token==".."){
            //2->cases if it is a absolute or relative path 
            //stack will be empty in starting during relative path
            if(stack.size()==0 or stack[stack.size()-1]==".."){
                stack.push_back(token);
            }
            else if(stack[stack.size()-1]!=""){  //if prev element is not a root slash which denotes absolute so we pop back 
                stack.pop_back();
            }
                
        
        }
        else{
            stack.push_back(token);
        }
    }
    
    //combine all elements 
    if(stack.size()==1 and stack[0]==""){
        return "/";
    }
    
    ostringstream oss;
    int i=0;
    for(auto str:stack){
        if(i!=0){
            oss<<"/";
        }
        oss<<str; //in empty stack token will be empty and thus / will be pushed 
        i++;
    }
    
    return oss.str();
    
    
    
    return "";
}


int main(){
    string s="../a/b/../c/././d/a///../../c/./";  //output: /a/c/c 
    string path=simplifyPath(s);
    cout<<"simplified path is: "<<path<<endl;
}