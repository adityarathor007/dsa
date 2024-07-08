#include <bits/stdc++.h>
using namespace std;

// The member states of the UN are planning to send people to the moon.They want them to be from different countries.You will be given a list of pairs of astronaut ID's.
//  Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

    class Graph
{
public:
    int V;
    list<int> *l;
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void traversal(int i, int &c, vector<bool> &visited)
    {
        visited[i] = true;
        for (int k : l[i])
        {
            if (!visited[k])
            {
                c += 1;
                traversal(k, c, visited);
            }
        }
        return;
    }
};

int count_pairs(int N, vector<pair<int, int>> astronauts)
{
    // complete this method
    Graph g(N);
    for (auto p : astronauts)
    {
        g.addEdge(p.first, p.second);
    }

    vector<bool> visited(N, false);
    vector<int> unique;

    int c = 1;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            c = 1;
            g.traversal(i, c, visited);
            unique.push_back(c);
        }
    }
    for(int x:unique){
        cout<<x<<endl;
    }
    // int ans = 0;
    // for (int i = 0; i < unique.size(); i++)
    // {
    //     for (int j = i + 1; j < unique.size(); j++)
    //     {
    //         ans += unique[i] + unique[j];
    //     }
    // }

    return N;
}

int main(){
    int n=5; //astronauts are labelled from 0 to n-1
    vector<pair<int, int>> astronauts = {{0, 1}, {2, 3}, {0, 4}};
    cout<<count_pairs(n,astronauts)<<endl;

}