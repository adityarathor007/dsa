#include <iostream>
#include <vector>
using namespace std;


int game(int n,vector<int> v,int k,int s,int e){
   if(s==e-(k-1)){
            
            int l = max(v[s],v[e]);
            int temp=0;
            if(l==v[s]){
                while(s<=e){
                    temp+=v[s];
                    s+=1;
                }
            }
            else{
               
                while(s<=e){
                    temp+=v[e];
                    e--;
                }
                
            }
            
       return temp; 
    }
    
    
    int opt1=0;
    int opt2=0;
    cout<<"the value of s is: "<<s<<endl;
    cout<<"the value of e is: "<<e<<endl;

    for(int i=s;i<s+k;i++){
        opt1+=v[i];
    }
    opt1+=min(game(n,v,k,s+2*k,e),game(n,v,k,s+k,e-k));
    for(int i=e;i>e-k;i--){
        opt2+=v[i];
    }
    opt2+=min(game(n,v,k,s,e-2*k),game(n,v,k,s+k,e-k));
    return max(opt1,opt2);
}


int MaxValue(int n, vector<int> v, int k){
    //Write your code here. Do not modify the function or parameters. You can use a helper function if needed.
    return game(n,v,k,0,n-1);
    
}



int main(){
    int n=6;
    vector <int> v = {10,15,20,9,2,5};
    int input;
    // while(cin>>input){
    //     v.push_back(input);
    // }
    int k=2;
    cout<<MaxValue(n,v,k)<<endl;
}