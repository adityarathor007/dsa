#include <bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> arr, int k)
{
    // complete this method
    int i = 0;
    int j = 0;
    int cs = 0;
    int count = 0;

    while (j < arr.size())
    {
        int num = arr[j];
        cs += num;
        
        if (cs == k)
        {
            count += 1;
            while(i<=j){
                i++;
                cs-=arr[i];
            }
        }
        j += 1;
    }
    
    return count;
}

int main() {
    vector<int> input = {10, 2, -2, -20, 10};
    int k=-10;
    cout<<cntSubarrays(input,k)<<endl;
    return 0;

}