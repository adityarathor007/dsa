#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int max = 0;
        int temp = 0;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        max = 0;

        sort(nums.begin(), nums.end());
        // vector<int>::iterator it;
        // it = unique(nums.begin(), nums.end());

        // nums.resize(distance(nums.begin(),it));
        for (int i = 0; i < nums.size(); i++)
        {

            temp = nums[i] * (nums.size() - i);

            if (temp >= max)
            {
                max = temp;
            }
        }

        cout << max << endl;
    }
    return 0;
}
 