#include <bits/stdc++.h>
using namespace std;

bool canMake(int days,vector<int>bloomDay,int m,int k){

        int cnt=0;
        int bouquet_cnt=0;
        for(int num:bloomDay){
            if(num<=days) cnt+=1;
            else{
                bouquet_cnt+=cnt/k;
                cnt=0;
            }
        }
        bouquet_cnt+=cnt/k;
        return bouquet_cnt>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=INT_MAX,r=INT_MIN;
        for(int days:bloomDay){
            l=min(l,days);
            r=max(r,days);
        }

        int min_days=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canMake(mid,bloomDay,m,k)){
                min_days=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return min_days;
    }

int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   while(t--){
       // for vector input: infile >> vec[i];
        int n;
        infile>>n;
        vector<int>bloomDay(n);
        for(int i=0;i<n;i++){
            infile>>bloomDay[i];
        }
        int m,k;
        infile>>m>>k;
        cout<<minDays(bloomDay,m,k)<<endl;

   }
return 0;
}
