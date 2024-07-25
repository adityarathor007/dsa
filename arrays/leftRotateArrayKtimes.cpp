#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//using a temp array(storing those elements in the temp which will go out of bound on left rotation similar is for rightRotation)
// void rotateArray(vector<int>&a,int k){
//     k=k%a.size();
//     int n=a.size();
//     vector<int>temp(n,0);
//     for(int i=0;i<k;i++){
//         temp[i]=a[i];
//     }
//     for(int i=k;i<n;i++){
//         a[i-k]=a[i];  //moves 3places back
//     }

//     int j=0;
//     for(int i=n-k;i<n;i++){
//         a[i]=temp[j];
//         j++;
//     }
// }



//without creating a new temp array

void rotateArray(vector<int>&a,int k){
    k=k%a.size();
    int n=a.size();
    reverse(a.begin(),a.end());
    reverse(a.begin(),a.begin()+(n-k));
    reverse(a.begin()+(n-k),a.end()); //reversing that part which went out of bound


}


int main(){
    vector<int> arr{1,2,3,4,5};
    int k=2;
    rotateArray(arr,k);
    for(auto x:arr){
        cout<<x<<",";
    }
    cout<<endl;
}