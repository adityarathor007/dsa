#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool outOfOrder(vector<int> arr, int i)
{
    int x = arr[i];
    if (i == 0)
    {
        return x > arr[1];
    }

    if (i == arr.size() - 1)
    {
        return x < arr[i - 1];
    }
    return x > arr[i + 1] or x < arr[i - 1];
}

pair<int, int> subArraySort(vector<int> a)
{

    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < a.size(); i++)
    {
        int x = a[i];
        if (outOfOrder(a, i))
        {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }

    int left = 0;
    while (smallest >= a[left])
    {
        left++;
    }

    int right = a.size() - 1;
    cout<<"the largest is "<<largest<<endl;
    while (largest <= a[right])
    {
        right--;
    }

    return {left, right};

    if (smallest == INT_MAX)
    {
        return{-1, -1};
    }

    return { 0, 0 };
}

int main()
{
    vector<int> arr = {1,2,3,4,5,8,6,7,9,10,11,12};
    auto p = subArraySort(arr);
    cout << p.first << " and " << p.second << endl;  //position start from 0 index

    return 0;
}
