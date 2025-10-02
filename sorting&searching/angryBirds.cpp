#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlaceBirds(vector<int> nests,int sep,int b){
    int birds=1;
    int prev_location=nests[0];
    for(int i=1;i<=nests.size()-1;i++){
        int c_location=nests[i];
        if(c_location-prev_location>=sep){
            birds++;
            prev_location=c_location;
            if(birds==b){
                return true;
            }
        }
    }
    return false;
}

int findLargestMinDist(int n,int b,vector<int> nests){
    int s=0;
    int e= nests[n-1]-nests[0];
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(canPlaceBirds(nests,mid,b)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}



int main(){
    
    int b=1;
    vector<int> nests={1,2,4,8,9};  //nests need to be sorted
    int n=nests.size();
    cout<<findLargestMinDist(n,b,nests)<<endl;
}