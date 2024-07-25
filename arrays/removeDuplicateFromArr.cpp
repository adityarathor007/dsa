#include <iostream>
#include<vector>
using namespace std;

//using the 2 pointer approach instead of using map which takes O(nlogn)

int removeDuplicate(vector<int>&arr){
    int i=0;
    int j=1;
    while(j!=arr.size()){
        if(arr[i]==arr[j]){
            j++;
        }
        else{
            i++;
            arr[i]=arr[j];
            
            j++;
        }
        
       
    }
    return i+1;
}


int main() {
    
    vector<int>arr{1,1,2,2,3,3,3};
    cout<<removeDuplicate(arr)<<endl;
    

    return 0;
}