
#include <climits>
#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

bool canRead(vector<int> books, int m,int val){
    int c_sum=0;
    int count=1;
    for(int i=0;i<books.size();i++){
        if(books[i]+c_sum>val){
            count++; //represent the next student
            c_sum=books[i];  //making sure that prev student does not read more than val
            if(count>m){
                return false;
            }
            
            
        }
        
        else{
            c_sum+=books[i];
        }
    }
    return true;
}




int minPages(vector<int> books, int m){
    int s=0;
    int e=0;
    for(int b:books){
            e += b;
            s = max(s,b);  //finding the maximum 
    }
    
    int result = INT_MAX;
    while(s<=e){
        int mid=(s+e)/2;
        // cout<<mid<<endl;
        if(canRead(books,m,mid)){
            result=min(result,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return result;
}


int main(){
    vector<int> i={10,20,30,15};
    sort(i.begin(),i.end());
    int k=2;
    cout<<minPages(i,k)<<endl;
    
}

