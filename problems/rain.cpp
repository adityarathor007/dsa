#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trappedWater(vector <int> a){

    int water=0;
    int n = a.size();
    vector <int> left(n,0);
    vector <int> right (n,0);
    int l = 0;
    int r = 0;
    for(int i=0;i<n;i++){
        if(l<a[i]){
            left[i]=a[i];
            l = a[i];
        }
        else{
            left[i]=l;
        }

        
        if(r<a[n-i-1]){
            right[n-i-1]=a[n-i-1];
            r=a[n-i-1];
        }
        else{
            right[n-i-1]=r;
        }


    }


    // for(int x:left){
    //     cout<<x<<endl;
    // }



    


    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        ans=min(left[i],right[i])-a[i];
        cout<<"the left element is "<<left[i]<<endl;
        cout<< "The right element is "<<right[i]<<endl;
        // cout<<ans<<endl;
        water+=ans;
    }

    return water;
    }

int main(){
    vector <int> arr={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappedWater(arr)<<endl;


    return 0;
}