#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>&arr1,vector<int>&arr2){
    int n=arr1.size();
    int m=arr2.size();

    if (n > m) return findMedianSortedArrays(arr2, arr1); //ensure that arr1 is smallers so that mid2 does not feel short of element required vs the number of elements it has


    //number of elements from arr1 into the left partition
    int l=0;
    int r=n;

    // left partition will be containing ceil((n+m)/2)
    //  such that if n+m is odd then median will be the max(l1,l2) in the left partition
    //  else median will be max(l1,l2)+min(r1,r2) such that the left and right partition will be containing equal number of elements

    while(l<=r){
        int mid1=l+(r-l)/2; //number of elements present in the left partition
        int mid2=(n+m+1)/2-mid1; //remaining elements from the arr2 for the left partition

        // cout<<mid1<<" "<<mid2<<endl;

        int l1=mid1>0?arr1[mid1-1]:INT_MIN;
        int l2=mid2>0?arr2[mid2-1]:INT_MIN;
        int r1=mid1<n?arr1[mid1]:INT_MAX;
        int r2=mid2<m?arr2[mid2]:INT_MAX;

        if(l1>r2) r=mid1-1; //decrease the number of elements taken from arr1 for making the final left arr
        else if(r1<l2) l=mid1+1; //increase the number of elements taken from arr1 for making the final left arr as then from arr2 there will be less elements on the final left side
        else{
            if((n+m)&1) return (double)max(l1,l2);
            else{
                // cout<<mid1<<" "<<mid2<<endl;
                return ((double) (max(l1,l2)+min(r1,r2)))/2;
            }
        }
    }
    return 0;
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
       stringstream ss1(line);
       vector<int>arr1;
       int num;
       while(ss1>>num) arr1.push_back(num);
       line="";
       vector<int>arr2;
       getline(infile,line);
       stringstream ss2(line);
       while(ss2>>num) arr2.push_back(num);

    //    for(int num1:arr1)cout<<num1<<", ";
    //    cout<<endl;

    //    for(int num2:arr2)cout<<num2<<", ";
    //    cout<<endl;

       cout<<findMedianSortedArrays(arr1,arr2)<<endl;
   }
return 0;
}
