#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int countMinSwaps(vector <int> arr){
    int ans=0;
    int n=arr.size();
    pair<int,int> ap[n];  // to maintain the indicies of the initial array

    for(int i=0;i<n;i++){
        ap[i].first=arr[i];
        ap[i].second=i;

    }

    sort(ap,ap+n);

    vector <bool> visited(n,false);

    for(int i=0;i<n;i++){
        int old_position=ap[i].second;

        //visited before or element is at correct position
        if(visited[i]==true or old_position==i){
            continue;
        }
        
        //visiting for the first time and also at the incorrect position
        int node=i;
        int cycle_len=0;

        while(!visited[node]){
            cout<<"the element is "<<ap[node].first<<endl;
            visited[node]=true;
            int next_node=ap[node].second;
            node=next_node;
            cycle_len+=1;
        }

        // cout<<cycle_len<<endl;
        ans+=cycle_len-1;


    }


    return ans;
}



int main(){
    vector <int> arr{2,4,5,1,3};
    cout<<countMinSwaps(arr)<<endl;
    return 0;

}