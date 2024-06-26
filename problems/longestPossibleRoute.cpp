#include <iostream>
#include <vector>
using namespace std;

pair<bool, int> move(vector<vector<int>> v, int x, int y, vector<vector<bool>> visited_matrix, int m, int n)
{
    // cout << "the current position is: " << x << "," << y << endl;

    // base case
    if (x == m - 1 and y == n - 1)
    {
        pair<bool, int> p = {true, 0}; // 0 to start counting
        return p;
    }

    if (x >= m or x < 0 or y >= n or y < 0)
    {
        pair<bool, int> p = {false, -1};
        return p;
    }

    else
    {

        visited_matrix[x][y] = true;
        pair<bool, int> res = {false, -1};
        // order of checking: below,right,left,up
        // remember if I make else if after if then the next condition wont be checked if (if statement) is satisfied thats why all are if

        // below check
        if (x + 1 < m and v[x + 1][y] != 0 and !visited_matrix[x + 1][y]) // !----Very important to make a check of next position before checking if the next position is zero -----!
        {

            auto p1 = move(v, x + 1, y, visited_matrix, m, n);
            if (p1.first)
            {
                res.first = true;
                res.second = max(res.second, p1.second);
            }
        }

        // right check
        if (y + 1 < n and v[x][y + 1] != 0 and !visited_matrix[x][y + 1])
        {
            auto p2 = move(v, x, y + 1, visited_matrix, m, n);
            if (p2.first)
            {
                res.first = true;
                res.second = max(res.second, p2.second);
            }
        }

        // left check
        if (x > 0 and v[x - 1][y] != 0 and !visited_matrix[x - 1][y])
        {
            auto p3 = move(v, x - 1, y, visited_matrix, m, n);
            if (p3.first)
            {
                res.first = true;
                res.second = max(res.second, p3.second);
            }
        }

        // up check
        if (y > 0 and v[x][y - 1] != 0 and !visited_matrix[x][y - 1])
        {

            auto p4 = move(v, x, y - 1, visited_matrix, m, n);
            if (p4.first)
            {
                res.first = true;
                res.second = max(res.second, p4.second);
            }
        }

        visited_matrix[x][y] = false;
        res.second += 1;
        return res;
    }
}

int findLongestPath(int m, int n, vector<vector<int>> v)
{

    vector<vector<bool>> visited_matrix(m, vector<bool>(n, false));
    int count = 0;
    pair<bool, int> ans = move(v, 0, 0, visited_matrix, m, n);
    return ans.second;
}

int main(){
    // int n; cin>>n;
    // int m; cin >> m;
    int m=3;
    int n=3;
    vector<vector<int>> input =
        {
            {1, 1, 1},

            {1, 1, 1},

            {0, 0, 1}

        };

    cout<<findLongestPath(m,n,input)<<endl;
    
    return 0;
}



