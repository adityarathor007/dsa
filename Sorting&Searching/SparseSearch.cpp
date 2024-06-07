#include<iostream>
using namespace std;

// modified binary search
int sparseSearch(string arr[],int n,string word){
    int s=0;
    int e=n-1;
   

    
    while(s<=e){
        int mid=(s+e)/2;
        int mid_left=mid-1;
        int mid_right=mid+1;
        if(arr[mid]==""){
            while(1){
            if(mid_left<s && mid_right>e) {
                   return -1;
            }
            else if(mid_left>=s && arr[mid_left]!=""){
                   mid=mid_left;
            
                   break;
             }
            else if(mid_right<=e && arr[mid_right]!=""){
                   mid=mid_right;
                   break;
               }
               mid_left-=1;
               mid_right+=1;
            }
            }
            
        if(arr[mid]>word){  //cant be else if as ""it wont"" check this condtion even when the word is there and non empty
                e=mid-1;
              
            }
        else if(arr[mid]<word){
                s=mid+1;
            }
        else{
                return mid;
            }
            
        }
        return -1;
}
 


int main(){
    string arr[]={"","","","bat","","c"};
    int n = sizeof(arr) / sizeof(arr[0]);
    string word="c";
    cout<<n<<endl;
    cout<<sparseSearch(arr,n,word)<<endl;
}