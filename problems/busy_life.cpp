#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool isCollide(int a,int b){
    
    if(a>=b){
        return false;
    }
    else{
        return true;
    }
}

int countActivites(vector<pair<int, int>> activities)
{
    // Complete this method
    int n = activities.size();
    int count=1;

    sort(activities.begin(), activities.end(), [](auto &left, auto &right)
              { return left.second < right.second; });
    int finish=activities[0].second;
    for(int i=0;i<n;i++){
        if(i!=0){
            if(!isCollide(activities[i].first,finish)){
                finish=activities[i].second;
                count++;
            }
        }
    }

    return count;
}


int main(){

    // vector<pair<int, int>>arr = { {7, 9},{0, 10},{4, 5},{8, 9},{4, 10},{5, 7} };
    vector<pair<int, int>>arr = { {1,4},{3,5},{4,7} };

    cout<<countActivites(arr)<<endl;

    return 0;
}