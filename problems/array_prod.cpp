#include <iostream>
#include <vector>
using namespace std;

// Expected Complexity O(N)
vector<int> productArray(vector<int> arr)
{
    int n=arr.size();
    vector<int> output(n, 1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i){
                output[i]*=arr[j];
            }
            else{
                continue;
            }
        }
    }

    return output;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    auto p = productArray(arr);
    for(int x:p){
        cout<<x<<endl;
    }

    return 0;
}
