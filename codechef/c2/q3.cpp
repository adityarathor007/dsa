#include <iostream>
#include <string>

using namespace std;

int check(const string &a)
{
    int k = 0;
    int c = 0;
    for (char ch : a)
    {
        if (ch == '1')
        {
            c++;
            k = max(k, c);
        }
        else
        {
            c = 0;
        }
    }

    return k;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        int ans = 0, c = 0, k = 0;
        cin >> n;
        string a;
        cin >> a;

        // Process the string

        for (int i = 0; i < n; i++)
        {
            if (a[i] == '0')
            {
                a[i] = '1';
                // cout << a << endl;
                c++;

                k = check(a);
                if (a[i + 1] == '1')
                {
                    a[i] = '0';
                }
                ans = max(ans, k);
            }
            else
            {
                c = 0;
            }
            if (i == n - 1)
            {
                k = check(a);
                ans = max(ans, k);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
