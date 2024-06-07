#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int>&array,int s,int e){

    int pivot=array[e];
    int i=s-1;
    for(int j=s;j<=e-1;j++){
        if(array[j]<pivot){
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[e]);
    return i+1;


}





int quickSelect(vector<int> &array,int s,int e,int k){
     
 // here no need of base case as in the worst case it will react to pivot  
     int p=partition(array,s,e);
    int m=(s+e)/2;
    if(p>k){
       return  quickSelect(array,s,p-1,k);
    }
    else if(p<k){
        return quickSelect(array,p+1,e,k);
    }
    else{
        return array[p];
    }
}





int main()
{   
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int s=0;
    int e=arr.size()-1;
    int k;
    cin>>k;
    cout<<quickSelect(arr,s,e,k)<<endl;




}

// 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