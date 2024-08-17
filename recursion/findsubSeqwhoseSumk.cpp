#include<iostream>
#include<vector>
using namespace std;


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!! ALL PATTERNS OF RECURSION  !!!!!!!!!!!!!!!!!!!!!!!
//TYPE1: printing all subseq whose sum is k
//TYPE2: printing just one subseq if exists not all
// TYPE3: giving the count of subseq's whose sum is k



// void findSubseqsRec(vector<int>&arr,vector<int>buff,int i,int n,int k,vector<vector<int>>&ans){
    
//     if(i==n){
//         if(k==0){
//             ans.push_back(buff);
//         }

//         return ;
//     }
//     if(k<0){ //this step is not needed as all subseq will reach the bottom of the tree i.e the base case

//         return ;
//     }
    //  if(k==0){ //this step is not needed as all subseq will reach the bottom of the tree
    //         ans.push_back(buff);
    //         return ;
    // }


//     findSubseqsRec(arr,buff,i+1,n,k,ans);
//     buff.push_back(arr[i]);
//     findSubseqsRec(arr,buff,i+1,n,k-arr[i],ans);

// }



// vector<vector<int>>findSubseqsWhoseSumisK(vector<int>&arr,int k){
//     vector<vector<int>>ans;
//     int n=arr.size();
//     vector<int>buff;
//     findSubseqsRec(arr,buff,0,n,k,ans);


//     return ans;
// }


//return only 1 of the subseq if exists
// bool checkSubseqRec(vector<int>&arr,vector<int>buff,int i,int n,int k,vector<vector<int>>&ans){
    
//     if(i==n){
//         if(k==0){
//             ans.push_back(buff);
//             return true;
//         }

//         return false; 
//     }
    

//     if(checkSubseqRec(arr,buff,i+1,n,k,ans)) return true;
//     buff.push_back(arr[i]);
//     if(checkSubseqRec(arr,buff,i+1,n,k-arr[i],ans)) return true;
    

//     return false;


// }


int countSubseqRec(vector<int>&arr,int i,int n,int k){
    if(k<0){ //still will be covered in base case but I dont want further recursion calls to be called if sum is negative as numbers as positive in the array
        return 0;  
    }
    if(i==n){
        if(k==0){
            return 1;
        }
        return 0;
    }
    
    int l=countSubseqRec(arr,i+1,n,k);
    int r=countSubseqRec(arr,i+1,n,k-arr[i]);
    return l+r;



}





int main(){
    vector<int>arr{1,2,1};
    

    vector<vector<int>>ans;
    vector<int>buff;
    int n=arr.size();
    int k=2;


    // auto ans=findSubseqsWhoseSumisK(arr,2)  

    // if(checkSubseqRec(arr,buff,0,n,k,ans)){
    //     for(auto x:ans[0]){
    //         cout<<x<<",";   
    //     }
    //     cout<<endl;
    // }
    // else{
    //     cout<<"no subseq exists"<<endl;
    // }
    
    cout<<countSubseqRec(arr,0,n,k)<<endl;


}

