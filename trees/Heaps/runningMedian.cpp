#include <iostream>
#include <queue>
using namespace std;

class Compare{
    public:
        bool operator()(float a,float b){
            return a>b;
        }
};

vector<float> runningMedian(vector<float> a){
    priority_queue<float> max;  //left heap
    priority_queue<float,vector<float>,Compare> min; //max heap
    max.push(a[0]);
    vector<float> ans;
    ans.push_back(a[0]);
    for(int i=1;i<a.size();i++){
        if(min.size()==max.size()){
            if(a[i]<=(min.top()+max.top())/2){  //compairing with previous median
                max.push(a[i]);
                ans.push_back(max.top());
            }
            else{
                min.push(a[i]);
                ans.push_back(min.top());
            }
           
        }
        else if(min.size()<max.size()){ 
            if(max.top()<=a[i]){
                min.push(a[i]);
            }
            else{
                min.push(max.top());
                max.pop();
                max.push(a[i]);
            }
            
            ans.push_back((min.top()+max.top())/2);
        }
        else{
            if(min.top()>=a[i]){
                max.push(a[i]);
            }
            else{
                max.push(min.top());
                min.pop();
                min.push(a[i]);
            }
             ans.push_back((min.top()+max.top())/2);
        }
        
       
    }
    
    return ans;
}


int main(){
    vector<float> arr={10,5,2,4};
    vector<float> medians=runningMedian(arr);
    for(float x:medians){
        cout<<x<<",";
    }
    cout<<endl;
}