#include<iostream>
#include<vector>
#include <climits>
#include<unordered_map>
using namespace std;


pair<int,int> find(vector<int>arr){
    unordered_map<int,int> m;
    for(auto x:arr){
        if(m.find(x)==m.end()){
            m[x]=0;
        }
        m[x]+=1;
    }
    int max_a=-1;
    int min_a=INT_MAX;
    int e1;
    int e2;

    //traversing the map
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>max_a){
            max_a=it->second;
            e1=it->first;

        }
        if(it->second<min_a){
            min_a=it->second;
            e2=it->first;

        }

    }

    return {e1,e2};
}

int main(){
    vector<int>arr{10,5,10,15,10,5};
    auto p=find(arr);   
    cout<<p.first<<","<<p.second<<endl;
}