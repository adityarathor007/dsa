#include<iostream>
using namespace std;


//in this we have to written the lenght of subseq which have all elements in sorted order


//the below method is for subset not subseq as it can occur by skipping some elements 
// int findLength(vector<int> v){
//     int ans=-1;
//     int c=0;
//     int i=0;
//     for(i=0;i<v.size()-1;i++){
//         c+=1;
//         if(v[i]>v[i+1]){
//             ans=max(ans,c);
//             c=0;
//         }
//     }
//     if(v[i-1]<v[i]){
//         ans+=1;
//     }
//     return ans;
// }


//bottom up appr
int findLength(vector<int>&v){
    int n=v.size();
    vector<int>dp(n,1); //will store the longestIncSubseq for ith element
    int len=1;


    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                dp[i]=max(dp[i],dp[j]+1);
                len=max(dp[i],len);
            }
        }
    }
   

    return len;

}


int main(){
    vector<int> v{50,4,10,8,30,100};
    cout<<findLength(v)<<endl;
}