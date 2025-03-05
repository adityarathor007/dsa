#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> rearrange(vector<int>& arr) {
        // Code here
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]!=-1){
            while(arr[i]!=i){
                int n1=arr[i];
                iter_swap(arr.begin()+i,arr.begin()+n1);    
                if(arr[i]==-1){
                    break;
                }
            }
        }
    }
    return arr;
}


int main(){
    vector<int>arr{1,0,2};
    arr=rearrange(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}