#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job{
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 

    Job() : id(0), dead(0), profit(0) {}
    Job(int a,int b,int c):id(a),dead(b),profit(c) {};
    
};

bool customSort(const Job &j1,const Job &j2){
        if(j1.profit==j2.profit){
            return j1.dead<j2.dead;
        }
        return j1.profit>j2.profit;
        
    }
    
vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,customSort);
        int timer=1;
        int profit=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(arr[i].dead>=timer){
                profit+=arr[i].profit;
                c+=1;
            }
            timer+=1;
        }
        
        vector<int>ans;
        ans.push_back(c);
        ans.push_back(profit);

        return ans;
    } 


int main(){
    int n=11;
    Job arr[11];
    int a,b,c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        arr[i]=Job(a,b,c);
    }
    auto ans=JobScheduling(arr,n);
    for(auto x:ans){
        cout<<x<<",";
    }
    cout<<endl;
    return 0;
}


// 8
// 1 6 306 
// 2 5 255
// 3 1 488
// 4 4 394
// 5 1 150
// 6 5 176 
// 7 7 108 
// 8 6 387

