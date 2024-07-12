#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int> ans;
    ans.push_back(0);
    int a;
    int b;
    int i=0;
    while(t--){
        cin>>a;
        cin>>b;
        if(a==0){
            ans.push_back(b);
        }
        else{
            for(int k=0;k<=i;k++){
                ans[k]=ans[k]^b;
            }
        }
        i++;
    }

    sort(ans.begin(),ans.end());

    for(auto x:ans){
        cout<<x<<",";
    }
    cout<<endl;
}
