#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>&arr){
    int prefixPrd=1,suffixPrd=1;
    int i=0,n=arr.size();
    int ans=INT_MIN;
    while(i<n){
        prefixPrd*=arr[i];
        suffixPrd*=arr[n-i-1];
        cout<<prefixPrd<<" "<<suffixPrd<<endl;
        ans=max(ans,max(prefixPrd,suffixPrd));
        if(prefixPrd==0) prefixPrd=1;
        if(suffixPrd==0) suffixPrd=1;
        i+=1;


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
