#include <bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int>&arr,int maxCap,int students){
    int curr=0;
    int partitions=1;
    for(int num:arr){
        curr+=num;
        if(curr>maxCap){
            curr=num;
            partitions+=1;
        }
    }
    return partitions<=students; //as the partitions can later be divided among itself as they are satisfy the need of less than maxCap
}




int findPages(vector<int>&arr,int k){
    if(k>arr.size()) return -1; //more number of students than number of books
    int l=INT_MIN;
    int r=0;
    for(int num:arr){
        l=max(num,l);
        r+=num;
    }

    int max_pages=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(canAllocate(arr,mid,k)){
            max_pages=mid;
            r=mid-1;
        }
        else l=mid+1;

    }
    return max_pages;
}




int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   infile.ignore();
   while(t--){
       //C-1: for vector input: infile >> vec[i]; and the numbers in the input file should be space seperated
       //C-2: if number of elements in the vector is not provided(after infile of t do infile.ignore() to remove the nextLine character from the buffer)
       string line;
       getline(infile,line);
       stringstream ss(line);
       vector<int>arr;
       int num;
       while(ss>>num) arr.push_back(num);
       int k;
       infile>>k;
       infile.ignore(); //for the next array input
       cout<<findPages(arr,k)<<endl;

   }
return 0;
}
