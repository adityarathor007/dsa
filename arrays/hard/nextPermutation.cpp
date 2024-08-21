#include<iostream>
using namespace std;
 
int findIndexJustGreater(vector<int>&v,int s,int n){
        int ans=s;
        for(int i=s+1;i<n;i++){
            if(v[i]<v[ans] and v[i]>v[s-1]){
                ans=i;
            }
        }
        return ans;
    }

    void nextPermutation(vector<int>& v) {
    int n=v.size();
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            // int post=upperbound(v.begin()+i,v.end())-v.begin(); fails
            int post=findIndexJustGreater(v,i+1,n);  //cant use upperbound as targeted_array needs to be sorted 
            swap(v[i],v[post]);
            sort(v.begin()+i+1,v.end());
            return;

        }
    }
    reverse(v.begin(),v.end());
    return ;
 
        
}


int main(){

}