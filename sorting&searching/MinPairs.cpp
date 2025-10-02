#include <climits>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

pair <int,int> minPairs(vector<int> a,vector<int> b){
    //sorting the 2nd array on which binary search will be applied
    sort(b.begin(),b.end());
    int min_diff=INT_MAX;
    pair<int,int> ans={-1,-1};
    
    
    for(int x:a){
        auto lb=lower_bound(b.begin(),b.end(),x); 
        int i=(lb-b.begin());
        if(i!=b.size()){  //what if x is 100 and no element in the array present with value greater than equal to it
        if(i!=0){
            int diff1=b[i]-x;
            int diff2=x-b[i-1];
            if(diff2<diff1){
                i=i-1;
            }
        }
            int curr_diff=abs(x-b[i]);
            if(curr_diff<min_diff){
                min_diff=curr_diff;
                ans={x,b[i]};
            }
        
    }
    }
    return ans;
    
    
}


int main(){
    vector<int> i1={-1,5,10,20,200};
    vector <int> i2={26,134,15,17};
    auto ans=minPairs(i1,i2);
    cout<<ans.first<<"-"<<ans.second<<endl;
}