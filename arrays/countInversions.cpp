#include <bits/stdc++.h>
using namespace std;


int merge(int s1,int e1,int s2,int e2,vector<int>&arr){
    int i=s1;
    int j=s2;
    int mergeCount=0;
    vector<int>temp;
    while(i<=e1 and j<=e2){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i+=1;
        }
        else{
            temp.push_back(arr[j]);
            mergeCount+=(e1-i+1);
            j+=1;
        }
    }
    while(i<=e1){
        temp.push_back(arr[i]);
        i+=1;
    }

    while(j<=e2){
        temp.push_back(arr[j]);
        j+=1;
    }

    for(int k=s1;k<=e2;k++){
        arr[k]=temp[k-s1];
    }

    return mergeCount;
}


int count_w_merge(int s,int e,vector<int>&arr){
    // cout<<s<<"  "<<e<<endl;
    if(s>=e) return 0;
    int count=0;
    int mid=s+(e-s)/2;
    count+=count_w_merge(s,mid,arr);
    count+=count_w_merge(mid+1,e,arr);
    count+=merge(s,mid,mid+1,e,arr);
    return count;
}

int inversionCount(vector<int>&arr){
    int n=arr.size();
    return count_w_merge(0,n-1,arr);

}



int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   infile.ignore();
   while(t--){
       string line;
       getline(infile,line);
       stringstream ss(line);
       vector<int>arr;
       int num;
       while(ss>>num) arr.push_back(num);

       cout<<inversionCount(arr)<<endl;

   }
return 0;
}
