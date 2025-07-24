#include<iostream>
#include<vector>
#include <queue>
using namespace std;


int leastInterval(vector<char>& tasks, int n) {
        
        // Formula based approach

        // unordered_map<char,int>mp;
        // int max_freq=0;
        
        // for(char task:tasks){
        //     mp[task]+=1;
        //     max_freq=max(max_freq,mp[task]);
        // }

        // int max_freq_task=0;
        // for(auto& a:mp){
        //     if(a.second==max_freq){
        //         max_freq_task+=1;
        //     }
        // }

        // int totalJobs=int(tasks.size());
        // return max(((max_freq-1)*(n+1)+max_freq_task),totalJobs);


        // using priority queue
        priority_queue<int>pq;
        vector<int>mp(26,0);

        for(char i:tasks){
            mp[i-'A']+=1;
        }

        for(int i=0;i<26;i++){
            if(mp[i]){
                pq.push(mp[i]);
            }
        }

        int time=0;
        while(!pq.empty()){
            vector<int>remain;
            int cycle=n+1;

            while(cycle and !pq.empty()){
                int max_freq=pq.top();
                pq.pop();
                if(max_freq>1){
                    remain.push_back(max_freq-1);
                }
                time+=1;
                cycle-=1;
            }

            for(int count:remain){
                pq.push(count);
            }
            if(pq.empty()) break;
            time+=cycle;
        }

        return time;
                
}