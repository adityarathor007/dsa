
#include <climits>
#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

bool canDivide(vector<int> books, int m,int val){
    int c_sum=0;
    int count=0;
    for(int i=0;i<books.size();i++){
        if(books[i]+c_sum>=val){
            c_sum=0;
            count++;
        }
        else{
            c_sum+=books[i];
        }
    }
    return count>=m;
}




int minPages(vector<int> books, int m){
    int s=books[0];
    int e=accumulate(books.begin(), books.end(),0);
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;
        if(canDivide(books,m,mid)){
            ans=maxValue(books,m,mid);
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}


int main(){
    vector<int> i={10,20,30,15};
    sort(i.begin(),i.end());
    int k=2;
    cout<<minPages(i,k)<<endl;
    
}