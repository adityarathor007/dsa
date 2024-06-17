#include<iostream>
#include <queue>
#include <map>
using namespace std;


vector<char> FindFirstNonRepeatingCharacter(string S){
    map<char,int>dict;  //we need hash map to keep track of the count as what if we deque the top element whenever it occurs again but this will fail in this scenario
    //abcacb as when we reach c in 2nd then it will say it is present in the queue then we will remove b(pop which removes the 1st element) and then output c(q.front()) which is wrong 
    // so the approach we follow is deque only the count is >= 0 of a char while iterating and if q is empty then output 0;
    vector<char> output;
    queue<char> q;
    for(char ch:S){
        cout<<ch<<endl;
        auto it = dict.find(ch);
        if(it!=dict.end()){
            dict[ch]+=1;
        }
        else{
            dict[ch]=1;
            q.push(ch);
        }
        while(!q.empty()){
            if(dict[q.front()]==1){
                break;
            }
            q.pop();  //removes the top element
        }
        
        if(q.empty()){
            output.push_back('0');
        }
        else{
            output.push_back(q.front());
        }
        
    }
    
    
    return output;
    
}


int main(){
    string s="abcacb";
    auto ans=FindFirstNonRepeatingCharacter(s);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}