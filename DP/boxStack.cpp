#include<iostream>
#include<vector>
using namespace std;
bool sortHeight(const vector<int>& v1, const vector<int>& v2)
{
    return v1[2] < v2[2];
}


bool canPlace(vector<int> b,vector<int> s){
    if(b[0]>s[0] and b[1]>s[1] and b[2]>s[2]){
        return true;
    }
    return false;
}

int maxHeight(vector<vector<int>> &c){
    
    sort(c.begin(),c.end(),sortHeight); //sorting on the basis of height and after this in the list of cuboid to check can be placed above it we have to check behind
    int n=c.size(); //denote the number of cuboids
    int m=c[0].size(); //denoting a particular cuboid entries size

    //printing the cuboids after sorting on the basis of height
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<c[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    vector<int> dp(n,0);  //it will store the max height that can be formed with that ith cuboid as the base and previous condition satisfying the dimension condition
    dp[0]=c[0][2];

    int max_height=0;

    for(int i=0;i<n;i++){
        dp[i]=c[i][2]; //start with base as this ith cuboid and thus current height for dp[i] is that cuboid's height
        for(int j=0;j<i;j++){
            if(canPlace(c[i],c[j])){
                dp[i]=max(dp[i],dp[j]+c[i][2]);
                
            }
            
        }
        max_height=max(max_height,dp[i]);
    }
 

    return max_height;

}

int main(){
    vector<vector<int>> cuboids={{2,1,2},{3,2,3},{2,2,8},{2,3,4},{2,2,1},{4,4,5}};
[50,45,20],[95,37,53],[45,23,12]
    // vector<vector<int>> cuboids={{7,11,17},{7,17,11},{11,7,17},{11,17,7},{17,7,11},{17,11,7}};
    cout<<maxHeight(cuboids)<<endl;
}