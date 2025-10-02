#include <iostream>
#include <vector>
using namespace std;

void rec_bubbleSort(vector<int>&vec,int n){
    if(n==1) return;
    for(int i=1;i<n;i++){
        if(vec[i-1]>vec[i]){
            swap(vec[i-1],vec[i]);
        }
    }

    return rec_bubbleSort(vec,n-1);
}


int main() {
    // Write C++ code here
    vector<int>vec{2,3,56,1,4};
    int n=vec.size();
    rec_bubbleSort(vec,n);
    for(int num:vec){
        cout<<num<<",";
    }
    cout<<endl;

    return 0;
}
