#include<iostream>
#include<vector>
using namespace std;


// helper function
void merge(vector <int>&array,int s,int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    vector<int> temp;
    while(i<=m and j<=e){
    if(array[i]>=array[j]){
        temp.push_back(array[j]);
        j++;
    }
    else{
        temp.push_back(array[i]);
        i++;
    }
    }   

    while(i<=m){
        temp.push_back(array[i]);
        i++;
    }

    while (j <= e)
    {
        temp.push_back(array[j]);
        j++;
    }

    // array=temp;        
    int k=0;
    for(int i=s;i<=e;i++){
        array[i]=temp[k++];

    }
    

}





//sorting function
void mergeSort(vector<int> &array, int s,int e){
    //base case
    if(s>=e){
        return ;
    }

    //recursive case
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