#include<iostream>
#include<string>
#include <vector>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};
    
    int i=0;
    int index;
    while(i<=big.length()){
        index=big.find(small,i);
        if(index==-1){
            break;
        }
        i=index+1;
        result.push_back(index);
    }
    return result;


}



int main(){
    string bigString = "I liked the movie, acting in movie was great!";
    string smallString = "movie";
    auto ans=stringSearch(bigString,smallString);
    for(int x:ans){
        cout<<x<<endl;
    }
}