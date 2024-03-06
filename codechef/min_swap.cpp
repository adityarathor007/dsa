#include <bits/stdc++.h>
using namespace std;

// counts min swap operations to convert a string

bool sameCharAdj(string str)
{
    int n = str.length(), i;
    set<char> st;
    st.insert(str[0]);
    for (i = 1; i < n; i++)
    {

        // If similar chars side by side, continue
        if (str[i] == str[i - 1])
            continue;

        // If we have found a char equal to current
        // char and does not exist side to it,
        // return false
        if (st.find(str[i]) != st.end())
            return false;

        st.insert(str[i]);
    }
    return true;
}
// that has similar characters together
int minSwaps(string str, int l, int r, int cnt, int minm)
{
    // Base case
    if (l >= r)
    {
        if (sameCharAdj(str))
            return cnt;
        else
            return INT_MAX;
    }

    for (int i = l; i <= r; i++)
    {
        for (int j = i + 1; j <= r; j++)
        {
            if (str[i] == str[j])
            {
                swap(str[i], str[j]);
                cnt++;

                int x = minSwaps(str, l + 1, r, cnt, minm);

                // Backtrack
                swap(str[i], str[j]);
                cnt--;

                minm = min(minm, x);
            }
        }
    }

    return minm;
}

// Driver code
int main()
{
    string str = "abbaacb";
    int n = str.length(), cnt = 0, minm = INT_MAX;
    cout << minSwaps(str, 0, n - 1, cnt, minm) << endl;
    return 0;
}
