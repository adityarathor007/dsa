#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int cntSubarraysWTargetSum(vector<int> arr, int k)
{
    // complete this method
    int count=0;
    int cs=0;
    int comp;
    unordered_map<int, int> table;
    for(int i=0;i<arr.size();i++){
        cs+=arr[i];
        if(cs==k){
            count++;
        }
        comp=cs-k;
        if(table.count(comp)){   //to check if key in the map or not 
            count+=table[comp];
        }

        table[cs]++;

    }
  

    
    return count;
}

int main() {
    vector<int> input = {10, 2, -2, -20, 10};
    int k=-10;
    cout<<cntSubarraysWTargetSum(input,k)<<endl;
    return 0;

}