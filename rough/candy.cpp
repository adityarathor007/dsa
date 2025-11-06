#include <bits/stdc++.h>
using namespace std;


int candy(vector<int>& ratings) {
    int n=ratings.size();
    vector<int>allocations(n,1);
    
    //doing allocation carrying left information
    for(int i=1;i<n;i++){
        if(ratings[i-1]<ratings[i]){
            allocations[i]=allocations[i-1]+1;
        }
    }

    //doing allocation carrying right information
    for(int i=n-1;i>0;i--){
        if(ratings[i-1]>ratings[i]){
            allocations[i-1]=allocations[i]+1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        // cout<<allocations[i]<<", ";
        ans+=allocations[i];
    }
    // cout<<endl;
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
       cout<<candy(arr)<<endl;
                               
   }
return 0;
}