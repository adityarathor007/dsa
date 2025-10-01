#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// input: vector of piles and time_limit h hours
// output: min bananas/hr i.e the speed of eating bananas/hr

int calcTime(vector<int>&piles,int k){
        long long time=0;
        for(int pile:piles){
            time+=ceil(((double)pile)/k);
        }
        if(time>INT_MAX) return INT_MAX;
        return time;
    }


int minEatingSpeed(vector<int>& piles, int h) {

        int l=1,r=INT_MIN;
        for(int num:piles){
            r=max(num,r);
        }

        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;
            int timeTaken=calcTime(piles,mid);
            if(timeTaken<=h){ //is able to eat in the deadline so try reducing the banana/hr
                ans=mid;
                r=mid-1;
            }
            else l=mid+1; //taking more time than deadline so increase the banana/hr
        }

        return ans;
    }




int main() {

    vector<int>piles{3,6,7,11}
    int time=4;
    cout<<minEatingSpeed(piles,time)<<endl;

    return 0;
}
