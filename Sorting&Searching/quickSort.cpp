#include <iostream>
#include <vector>
using namespace std;





int partition(vector <int> &array,int s,int e){

    int pivot=array[e]; 
    int i=s-1;
    for(int j=s;j<e;j++){
        if(array[j]<pivot){
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[e]);  // swap the pivot and the nxt of smaller 
    return i+1;



}



void quickSort(vector<int> &array,int s,int e){

    // base case
    if(s>=e){
        return;
    }

    //Rec Case
    int p=partition(array,s,e);  //p is the index of the pivot element 
    quickSort(array,s,p-1);
    quickSort(array,p+1,e);




}





int main(){
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};

    int s = 0;
    int e = arr.size() - 1;
    quickSort(arr, s, e);

    for(int x:arr){
        cout<<x<<endl;
    }

}