#include <bits/stdc++.h>
using namespace std;

  double findMaxAverage(vector<int>& nums, int k) {
        double maxWinAvg=INT_MIN;
        int i=0,j=0;
        int cSum=0;
        int n=nums.size();
        while(j<n){
            cSum+=nums[j];
            if(j-i+1==k){
                maxWinAvg=max(maxWinAvg,((double)cSum)/k);
                cSum-=nums[i];
                i+=1;
            }
            j+=1;
        }

        return maxWinAvg;
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
       infile.ignore();
       cout<<findMaxAverage(arr,k)<<endl;

   }
return 0;
}
