#include<iostream>
#include <cstring>
using namespace std;

string keypad[]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printKeypadOutput(string input,string output,int i=0){
    if(input[i]=='\0'){   //as string is null terminated whereas in character array you have to add null terminated character
        cout<<output<<endl;
        return ;
        
    }
    int current_digit=input[i]-'0'; // as input is a character and now it becomes a integer
    if(current_digit==0 or current_digit==1){
        printKeypadOutput(input, output,i+1);// as they are not mapped to any string
    }
    
    for(int k=0;k<keypad[current_digit].size();k++){
        printKeypadOutput(input, output+keypad[current_digit][k],i+1); //in each iteration taking one character of current keypad group of string and moving to the next index
    }
    
    
}


int main(){
    string input;
    cin>>input;
    string output;
    printKeypadOutput(input,output);
    
}