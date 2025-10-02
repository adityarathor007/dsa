#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// constraint is the array needs to be sorted






int lower_bound(vector<int> arr, int k)
{
    int s=0;
    int e=arr.size()-1;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==k){
            ans=mid;
            e=mid-1;

        }
        else if(arr[mid]>k){
            e=mid-1;

    }
        else if(arr[mid]<k){
            s=mid+1;
        }

    }
    return ans;
    
}

int upper_bound(vector<int> arr, int k)
{
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > k)
        {
            e = mid - 1;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
    }
    return ans;
}

int find_freq(vector<int> arr, int k){
    int l=lower_bound(arr,k);
    int r=upper_bound(arr,k);
    if(l==r and l==-1){
        return -1;
    }
    return r-l+1;
}

    int main()
{
    vector<int> arr={0,1,1,2,3,3,3,3,4,5,5,5,10};
    int key;
    cin>>key;
    cout<<find_freq(arr,key)<<endl;


    //STL function
    cout<<upper_bound(arr.begin(),arr.end(),3)-lower_bound(arr.begin(),arr.end(),3)<<endl;  //compiler knows this is a diff function as the parameters passed are different 

}