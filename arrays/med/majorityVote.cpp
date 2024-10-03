#include <iostream>
#include<vector>
using namespace std;

// brute force would be count the freq of each element and store in the map


// using moore voting algorithm
// (intution is that if an element occurs more than n/2 than 
// that that element count be made max to max 1 by other elements by reducing the count when it does not occur
// also if not continous still no element will be able to dominate in count
int majorityElement(vector<int>& arr) {
    int n=arr.size();
    int count=0;
    int ele;x   
    for(int i=0;i<n;i++){
        if(count==0)  ele=arr[i];
        if(arr[i]==ele) count+=1;
        else count-=1;
    }

    int verifyc=0;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            verifyc+=1;
        }

    }
    if(verifyc>n/2){
        return ele;
    }
    return -1;

}