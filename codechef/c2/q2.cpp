#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int a, m;
        cin >> a;
        cin >> m;
        if (a < 50)
        {
            cout << "Z" << endl;
        }
        else if (m < 50 & m >= 50)
        {
            cout << "F" << endl;
        }
        else
        {
            cout << "A" << endl;
        }
    }
}
