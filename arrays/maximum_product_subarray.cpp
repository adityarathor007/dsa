#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
        int n=nums.size(),ans=INT_MIN;
        int prefixPrd=1,suffixPrd=1;  //because if there are odd number of negatives then the max_ans will be from starting to before the
        // last neg or after the first neg to the last element (with partitions in 0 like 0 is the new starting point of the new subarray)

        for(int i=0;i<n;i++){
            prefixPrd*=nums[i];
            suffixPrd*=nums[n-i-1];
            ans=max(ans,max(prefixPrd,suffixPrd));
            if(prefixPrd==0) prefixPrd=1;
            if(suffixPrd==0) suffixPrd=1;
        }

        return ans;
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
       cout<<"Input: "<<endl;
       for(int num:arr) cout<<num<<", ";
       cout<<endl;
       cout<<"Output: "<<endl;
       cout<<maxProduct(arr)<<endl;

   }
return 0;
}
