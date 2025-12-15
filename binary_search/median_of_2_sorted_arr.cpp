#include <bits/stdc++.h>
using namespace std;

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int i=0,j=m;
        int elem_in_left=(m+n+1)/2;
        while(i<=j){
            // cout<<i<<" "<<j<<endl;
            int mid=i+(j-i)/2;
            int l1=mid!=0?nums1[mid-1]:INT_MIN;
            int l2=mid!=m?nums1[mid]:INT_MAX;
            int from_nums2=elem_in_left-mid;
            int r1=from_nums2!=0?nums2[from_nums2-1]:INT_MIN;
            int r2=from_nums2!=n?nums2[from_nums2]:INT_MAX;
            // cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
            if(l1<=r2 and r1<=l2){
                if((n+m)&1) return max(l1,r1);
                else{
                    return ((double)(max(l1,r1)+min(l2,r2)))/2;
                }
            }
            else if(l1>r2){
                j=mid-1;
            }
            else i=mid+1;
        }
        return -1;

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
