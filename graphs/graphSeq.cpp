#include <bits/stdc++.h>
using namespace std;

void traversal(int i, int j, vector<vector<int>> &matrix, vector<vector<bool>> &visited, int c, int &ans)
{
    visited[i][j] = true;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    int n = matrix.size();
    int m = matrix[0].size();
    cout<<"the starting number is: "<<matrix[i][j]<<endl;
    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 and ny >= 0 and nx < n and ny < m and !visited[nx][ny] and matrix[nx][ny] > matrix[i][j])
        {
            c += 1; 
            traversal(nx, ny, matrix, visited, c, ans);
            c -= 1;
        }
    }
    visited[i][j]=false;
    
    ans = max(c, ans);
    
    cout<<ans<<endl;
    return;
}

int longestPathSequence(vector<vector<int>> matrix)
{
    // Complete this function
    //  Hint : You may need to use DP, to store the longestPath length for already visited 'states'
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = INT_MIN;
    int c = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                c = 1;
                traversal(i, j, matrix, visited, c, ans);       
            }
        }
    }

    return ans;
}

int main(){
    // vector<vector<int>> in={{10,9},{11,12},{1,15}};
    vector<vector<int>> in = {{0, 2, 4, 3, 2}, {7, 6, 5, 5, 1}, {8, 9, 7, 18, 14}, {5, 10, 11, 12, 13}};
    
    cout<< longestPathSequence(in) << endl;
}