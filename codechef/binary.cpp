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
        int a[32];
        int c = 0;
        while (n > 0 )
        {
            a[c] = n % 2;

            n = n / 2;
            c++;
        }
        a[c] = 1;
        for (int i = c; i >= 0; i--)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
