#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>&vec,int n){
    for(int i=2;i<n;i++){
        for(int j=i;j>=1 && vec[j]<vec[j-1];j--){  //if the condition of it violated then it is stopped as before elments will be obviously smaller than the j-1 element as the array is sorted
            swap(vec[j],vec[j-1]);
        }
    }
}



void rec_InsertionSort(vector<int>&vec,int n){
    if(n==1) return;

    rec_InsertionSort(vec,n-1);

    for(int j=n-1;j>=1 && vec[j]<vec[j-1];j--){
        swap(vec[j],vec[j-1]);
    }

    return ;
}



int main(){
    vector<int>vec{2,3,56,1,12};
    int n=vec.size();
    rec_InsertionSort(vec,n);
    for(int num:vec){
        cout<<num<<",";
    }
    cout<<endl;
}
