#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

pair<int, int> minDifference(vector<int> a, vector<int> b)
{   
    // pair <int,int> ans;
    // int min_diff=INT_MAX;
    // int diff;
    // for(int x:a){
    //     for(int y:b){
    //         diff=abs(y-x);
    //         if (diff<min_diff){
    //             cout<<"first array element is "<<x<<endl;
    //             cout<<"second array element is "<<y<<endl;
    //             ans.first=x;
    //             ans.second=y;
    //             min_diff=diff;
    //         }
    //     }
    // }
    // return ans;

   
    vector<int> result;
    // iterate over 1 and do binary search
    int p1, p2;

    int diff = INT_MAX;

    for (int x : a)
    {
        auto lb = lower_bound(b.begin(), b.end(), x) - b.begin();

        if (lb >= 1 and x - b[lb - 1] < diff)
        {
            diff = x - b[lb - 1];
            p2 = b[lb - 1];
            p1 = x;
        }

        if (lb != b.size() and b[lb] - x < diff)
        {
            diff = b[lb] - x;
            p1 = x;
            p2 = b[lb];
        }
    }

    return {p1, p2};

}


int main(){
    vector<int> arr1 = {23, 5, 10, 17, 30};
    vector <int> arr2={26, 134, 135, 14, 19};
    auto p = minDifference(arr1,arr2);



    cout << p.first << " and " << p.second << endl;

    return 0;
}