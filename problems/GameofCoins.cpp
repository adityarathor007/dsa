#include <bits/stdc++.h>
using namespace std;



int findMaxSum(int n, vector<int> v, int s, int e)
{
    if(s==e|s==e-1){
        return max(v[s],v[e]);
    }
    int opt1=v[s]+min(findMaxSum(n,v,s+1,e-1),findMaxSum(n,v,s+2,e));
    int opt2=v[e]+min(findMaxSum(n,v,s+1,e-1),findMaxSum(n,v,s,e-2));
    return max(opt1,opt2);


}

int MaxValue(int n, vector<int> v)
{

    int i=0;
    int j=n-1;
    cnt=findMaxSum(n, v, i, j);
    return cnt;
    // Write your code here. Do not modify the function or parameters. You can use a helper function if needed.
}


int main(){
    int n;
    cin>>n;
    int input;
    vector<int> v;
    while (cin >> input) // enter any non-integer to end the loop
    {
        v.push_back(input);
    }

    cout<<MaxValue(n,v)<<endl;
    return 0;
}