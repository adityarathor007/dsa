#include <iostream>
#include <vector>
using namespace std;
 
 
bool is_digit(string& str){
        if(str==""){
            return false;
        }
        
        bool started=false;
        if(str=="0"){
            return true;
        }
        for(auto x:str){
            if(!isdigit(x)){
                return false;
            }
            
            if(x!='0' and !started){
                started=true;
            }
            else if(x=='0' and !started){
                return false;
            }
            
        }
        
        return true;
    }
    
    int isValid(string str) {
        // code here
    
        string cs;
        int count=0;
        for(auto x:str){
            if(x=='.'){
                 count+=1;
                if(count>3){
                    return false;
                }
                if(!is_digit(cs)){
                    return false;
                }
                else if(stoi(cs)<0 or stoi(cs)>255){
                    return false;
                }
                cs="";
               
            }
            else{
                cs.push_back(x);
            }
        }
        if(!is_digit(cs)){
                    return false;
                }
                else if(stoi(cs)<0 or stoi(cs)>255){
                    return false;
                }
        if(str=="" or count!=3){
            return false;
        }

        return true;
    }

int main(){
    string str="98.80.224.423";
    isValid(str)?cout<<"is a valid ip address":cout<<"not a valid ip address";
    cout<<endl;
}