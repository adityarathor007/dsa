#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countActivites(vector<pair<int, int>> activities)
{
    // Complete this method
    int n=activities.size();
    vector <int> diff;
    for(int i=0;i<n;i++){
        diff[i]=(activities[i].second-activities[i].first);
    }
    sort(diff.begin(),diff.end());

    return n;
}


int main(){

    vector<pair<int, int>>arr = { {7, 9},{0, 10},{4, 5},{8, 9},{4, 10},{5, 7} };
    cout<<countActivites(arr)<<endl;

    return 0;
}