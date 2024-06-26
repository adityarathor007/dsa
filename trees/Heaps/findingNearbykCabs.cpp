#include <iostream>
#include <queue>
using namespace std;



class Cab{
public:
    string name;
    int x;
    int y;
        Cab(string name,int x,int y){
            this->name=name;
            this->x=x;
            this->y=y;
        };
        
        int dist() const{
            return x*x+y*y; //returing the square as the underoot will be greater if square is greater as all distance are greater than 1
        }
};

class CabCompare{
    public:
        bool operator()(const Cab& A,const Cab& B){
            return A.dist()<B.dist(); // as constructing the max heap
        }
};


bool compCabBasedOnDist(Cab A, Cab B){
    return A.dist()<B.dist();   //A is the element to be kept first 
}


void printNearestCabs(vector<Cab> cabs,int k){
    priority_queue<Cab,vector<Cab>,CabCompare> max_heap(cabs.begin(),cabs.begin()+k); //for first k element made the max heap
    
    //remaining cabs
    for(int i=k;i<cabs.size();i++){
    auto cab=cabs[i];
    if(cab.dist()<max_heap.top().dist()){   //as the top will contain the maximum element possible 
        max_heap.pop();
        max_heap.push(cab);
    }

    }
    
    vector<Cab>ans;
    while(!max_heap.empty()){
        // cout<<max_heap.top().name<<endl;
        ans.push_back(max_heap.top());
        max_heap.pop();
    }
    
    sort(ans.begin(),ans.end(),compCabBasedOnDist);
    
    for(auto cab:ans){
        cout<<cab.name<<endl;
    }
    
    return ;
    
    
}


int main(){
    int n,k;
    cin>>n;
    cin>>k;
    
    vector<Cab> cabs;
    string id;
    int x,y;
    
    for(int i=0;i<n;i++){
        cin>>id >>x>>y;
        Cab cab(id,x,y);
        cabs.push_back(cab);
        }
        
        printNearestCabs(cabs,k);
    
    
}