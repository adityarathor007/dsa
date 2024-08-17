#include<iostream>
#include<vector>
using namespace std;

    
    void recFun(vector<int>& candidates,vector<int>buff,int i,int n,int target,vector<vector<int>>&ans){
        cout<<target<<"-"<<i<<endl;

        if(target==0){
            ans.push_back(buff);
            return ;
        }
        if(i==n or target<0){
            return ;
        }

        //igonoring arr[i] num
        recFun(candidates,buff,i+1,n,target,ans);
        buff.push_back(candidates[i]);
        recFun(candidates,buff,i,n,target-candidates[i],ans);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>buff;
        recFun(candidates,buff,0,n,target,ans);

        return ans;
    }

    int main(){
        vector<int>candidates{2,3,6,7};
        int target=7;
        
        auto ans=combinationSum(candidates,target);
        for(int i=0;i<ans.size();i++){
            for(int x:ans[i]){
                cout<<x<<",";
            }
            cout<<endl;
        }

        return 0;

    }