#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double findRoot(int number,int d){
    int s=0;
    int e=number;
    double ans=0;
    while(s<=e){  //using binary search we found the integer part
        int mid=(s+e)/2;
        if(mid*mid<=number){
            ans=mid;
            s=mid+1;
            
        }
        else{
            e=mid-1;
          
        }
    }
    cout<<"the integer part of the ans: "<<ans<<endl;
   
    if(ans*ans==number){
        return ans;
    }
    
    
    float inc=0.1;
    
     //linear search as we have to search only for 9 number for decimal and logN and root(N) wont be of much difference
    for(int i=1;i<=d;i++){

        while(ans*ans<=number){
           ans+=inc;
        }
        //one step back for ans;
        ans-=(inc);
        inc=inc/10.0;
        
    }

    return ans;
}


// finding the floor of the square root using binary search

//   long long int findFloorRoot(long long int n) {
//         // Your code goes here
//         if(n<=0){
//             return 0;
//         }
//         long long int low=1;
//         long long int high=n;
//         long long ans=0;

//         while(low<=high){
            
//             long long int mid=(low+high)>>1;
//             // cout<<mid<<endl;
//             long long int sqMid=mid*mid;
//             if(sqMid==n){
//                 ans=mid;
//                 break;
//             }
//             if(sqMid>n) high=mid-1;
            
//             else{
//                 low=mid+1;  
//                 ans=mid;
//             } 
//         }
        
//         return ans;
//     }

int main(){
    int number;
    cin>>number;
    // int dec_place;
    // cin>>dec_place;
    // cout<<findRoot(number,dec_place)<<endl;
    cout<<findFloorRoot(number)<<endl;
    
    
}