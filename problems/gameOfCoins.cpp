#include <iostream>
using namespace std;

int game(int n,vector<int> v,int s,int e)
{
    if(s==e| s==e-1){ //e for odd number of elements and e-1 for for even number of elements 
        return max(v[s],v[e]);
    }
    
    int opt1=v[s]+min(game(n,v,s+2,e),game(n,v,s+1,e-1)); //min as the 2nd opponent is also smart so he will ensure that the other player gets the minimum
    int opt2=v[e]+min(game(n,v,s+1,e-1),game(n,v,s,e-2));
    return max(opt1,opt2);
}


int MaxValue(int n, vector<int> v){
    //Write your code here. Do not modify the function or parameters. You can use a helper function if needed.
    return game(n,v,0,n-1);
    
    
}


int main(){
    int n;
    vector <int> v;
    cin>>n;
    int input;
    while(cin>>input){
        v.push_back(input);
    }
    cout<<MaxValue(n, v)<<endl;
    return 0;
}

