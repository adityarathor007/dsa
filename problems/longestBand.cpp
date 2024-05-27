#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestBand(vector<int> arr){
    int largest_band=0;

    int n=arr.size();
    unordered_set<int> s;
    for(int x:arr){
        s.insert(x);
    }

    for (auto element:s){
        int len=1;
        int parent=element-1;
        if (s.find(parent) == s.end())
        {
           int next_no=element+1;
           int cnt=1;
           while(s.find(next_no)!=s.end()){
            next_no++;
            cnt++;
           }
            if(cnt>largest_band){
                largest_band=cnt;
            }
        }
    }
        

    return largest_band;
}



int main()
{
    vector<int> arr{1,9,3,0,18,5,2,10,7,12,6};

    cout<<longestBand(arr)<<endl;

    return 0;
}