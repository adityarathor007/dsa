#include <iostream>
#include<vector>
#include<climits>
using namespace std;


int findMinIndex(vector<int>v,int s,int e) {
    // code
    int result;
    int num=INT_MAX;
    for(int i=s;i<=e;i++){
        if(num>v[i]){
            num=v[i];
            result=i;
        }
    }

    return result;
}


void selectionSort(vector<int>& v,int n) {
    
    for (int i = 0; i < n; i++) {
        int j=findMinIndex(v,i,n-1);
        swap(v[i],v[j]);
        
    }
    // return result;
}

void bubbleSort(vector<int> &v,int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }

    // return result;
}

void insertionSort(vector<int>&v,int n){
    for(int i=0;i<n;i++){
        for(int j=i;j>0;j--){
            if(v[j]<v[j-1]){
                swap(v[j],v[j-1]); //swapping untill a less than element before it found

            }
            else{
                break;
            }
        }
    }
}


void merge(vector<int>&arr,int s,int e){
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    
    vector<int>temp;
    
    while(i<=mid and j<=e){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }

    }
    
    
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=e){
        temp.push_back(arr[j]);
        j++;
    }
    // merged set 
    // for (int k = 0; k < temp.size(); k++) {
    //     cout<<temp[k]<<",";
    // }

    // cout<<endl;

    
    int l=0;

    for(int k=s;k<=e;k++){
        arr[k]=temp[l++]; //it is important that temp starts from zero as indexing of arr and indexing of temp is diff
    }

    return ;
}


void mergeSort(vector<int>&v,int s,int e) {
    if(s>=e){
        return ;
    }
    int mid=(s+e)/2;
    mergeSort(v,s,mid);
    mergeSort(v,mid+1,e);
    merge(v,s,e);

    return ;
    
}



int qsHelper(vector<int>&v,int s,int e) {
    int pivot=v[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }

    }
    swap(v[i+1],v[e]); //swap with last element next to smallest wrt to pivot with the pivot
    return i+1;
}

void quickSort(vector<int>&v,int s,int e){
    if(s<e){
        int partition=qsHelper(v,s,e);
        quickSort(v,s,partition-1);
        quickSort(v,partition+1,e);
    }
}





int main() {    
    
    vector<int>v{3,5,1,7,9,2};
    int n=v.size();
    // selectionSort(v,n);
    // bubbleSort(v,n);
    // insertionSort(v,n);
    // mergeSort(v,0,n-1); //O(nlogn)
    quickSort(v,0,n-1);


    //printing after sorting
    for (int i = 0; i < n; i++) {
        cout<<v[i]<<",";
        // code
    }
    cout<<endl;




    return 0;
}