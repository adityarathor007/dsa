#include<iostream>
#include<vector>
using namespace std;


// helper function
void merge(vector <int>&array,int s,int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    vector<int> temp;
    while(i<=m or j<=e){
    if(array[i]>array[j]){
        temp.push_back(array[j]);
        i++;
    }
    else{
        temp.push_back(array[i]);
        j++;
    }
    }


    array=temp;
    return ;

}





//sorting function
void mergeSort(vector<int> &array, int s,int e){
    //base case
    if(s>=e){
        return ;
    }

    int mid=(s+e)/2;
    mergeSort(array,s,mid);
    mergeSort(array,mid+1,e);
    return merge(array,s,e);
}







int main(){

    vector <int> arr{10,5,2,0,7,6,4};

    int s=0;
    int e=arr.size()-1;
    mergeSort(arr,s,e);
    for (int x:arr){
        cout<<x<<", ";
    }
    cout<<endl;



    return 0;
}