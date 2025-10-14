#include <bits/stdc++.h>
using namespace std;


int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int max_len=0;
        int current_zeros=0;
        while(j<n){
            if(nums[j]==0){
                current_zeros+=1;
            }
            if(current_zeros>k){
                if(nums[i]==0) current_zeros-=1;
                i+=1;
            }

            max_len=max(max_len,j-i+1);
            j+=1;
        }
        max_len=max(max_len,j-i);
        return max_len;
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
       cout<<longestOnes(arr)<<endl;

   }
return 0;
}
