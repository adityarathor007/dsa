#include <iostream>
#include <string>

using namespace std;

int maxPresentDays(const string &s)
{
    int max_present = 0;
    int current_length = 0;

    for (char c : s)
    {
        if (c == '0')
        {
            current_length++;
        }
        else
        {
            max_present = max(max_present, current_length);
            current_length = 0;
        }
    }

    // Update max_present if the last substring ends with '0's
    if (current_length > 0)
    {
        max_present = max(max_present, current_length);
    }

    return max_present;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << maxPresentDays(s) << endl;
    }
    return 0;
}
