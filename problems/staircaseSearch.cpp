#include <bits/stdc++.h>
using namespace std;

pair<int, int> search(int m, int n, vector<vector<int>> v, int k)
{
    // write your code here.
    int i=0;
    int j=n-1;


    while (i <= m and j >= 0)
    {
        // cout<<v[i][j]<<endl;
        if (v[i][j] == k)
        {
            return {i, j};
        }
        else if (v[i][j] >= k ){
            j--;
        }

        else if (v[i][j] < k)
        {
            i++;
        }
        
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> input = {{1, 4, 9}, {2, 5, 10}, {6, 7, 11}};
    int m = 3;
    int n = 3;
    int k;
    cin>>k;
    auto ans = search(m, n, input, k);
    cout << ans.first<<"," << ans.second<< endl;
}