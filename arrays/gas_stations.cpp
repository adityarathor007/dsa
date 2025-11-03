class Solution {
public:
    // int canComplete(int i,vector<int>&gas,vector<int>&cost){
    //     int fuel=gas[i];
    //     int n=gas.size();
    //     int start_i=i;

    //     bool started=false;
    //     while(i!=(start_i)%n or !started){
    //         // cout<<fuel<<endl;
    //         i=(i+1)%n;
    //         started=true;
    //         int prev_cost=i!=0?cost[i-1]:cost[n-1];
    //         if(fuel<prev_cost){
    //             // cout<<"not sufficient fuel for index: "<<start_i<<endl;
    //             return -1;
    //         }
    //         fuel=fuel-prev_cost+gas[i];

    //     }
    //     return i;
    // }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       // O(n^2) solution
    //    int n=cost.size();
    //    for(int i=0;i<n;i++){
    //      if(canComplete(i,gas,cost)!=-1) return i;
    //    }
    //    return -1;

        int n=cost.size();
        int totalGas=0,totalCost=0;
        for(int i=0;i<n;i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
        }

        if(totalGas<totalCost){
            return -1;
        }

        int currentGas=0,start=0;

        // now it is guranteed that solution exist so we dont need to check in circular fashion so we start checking from starting
        for(int i=0;i<gas.size();i++){
            currentGas+=gas[i]-cost[i];
            if(currentGas<0){
                currentGas=0; //restarting it from next index
                start=i+1;
            }
        }

        return start;

    }
};
