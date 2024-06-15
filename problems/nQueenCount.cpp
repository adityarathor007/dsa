#include <iostream>
#include <vector>
using namespace std;

int cnt;


bool canPlace(vector<vector<int>> &input, int n, int x, int y)
{
    // check for column
    for (int i = 0; i < x; i++)
    {
        if (input[i][y] == 1)
        {
            return false;
        }
    }

    // check for left diagonal
    int i = x - 1;
    int j = y - 1;
    while (i >= 0 and j >= 0)
    {
        if (input[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    // checking the right diagonal
    i = x - 1;
    j = y + 1;
    while (i >= 0 and j < n)
    {
        if (input[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

void placeNQueen(vector<vector<int>> &input, int n, int i)
{
    if (i == n)
    {
        cnt++;

        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (canPlace(input, n, i, j))
        {
            input[i][j] = 1;
            placeNQueen(input, n, i + 1);
            input[i][j] = 0;
        }
    }
}

int nQueen(int n)
{
    // Write your code below. Do not modify this function or parameters. You can use helper function if needed.
    int i = 0;
    cnt=0;
    vector<vector<int>> input(n, vector<int>(n, 0));
    placeNQueen(input, n, i);


    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << input[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cout << nQueen(n) << endl;
}