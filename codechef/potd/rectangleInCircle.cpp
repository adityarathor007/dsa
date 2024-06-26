#include<iostream>
using namespace std;




int main(){
    int n;
    cin>>n;
    int a=(2*n);
    int count=0;
    
    for(int i=1;i<a;i++){
        for(int j=1;j<a;j++){
            if(i*i+j*j<=a*a){
                count+=1;
            }
        }
        
    }
   
    cout<<count<<endl;
   
}