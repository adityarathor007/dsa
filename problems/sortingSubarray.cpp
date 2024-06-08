#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> subarraySorting(vector<int> a){
    vector <int> b=a;
    pair<int,int> ans;
    int n=a.size();
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(b[i]!=a[i]){
            ans.first=i;
            while(b[i]!=a[i]){
                i++;
            }
            ans.second=i-1;
            return ans;
        }
    }
    
    
    
    
    
    
    return {-1,-1};
}

int main(){
    vector <int> input={0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};
    auto ans=subarraySorting(input);
    cout<<ans.first<<"-"<<ans.second<<endl;
}