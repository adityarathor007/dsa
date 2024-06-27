#include <iostream>
#include <unordered_map>

using namespace std;


class Point{
    
    public:
    int x;
    int y;
        
        Point(int x,int y){
            this->x=x;
            this->y=y;
        }
};

int countTriangles(vector<Point> a){
    unordered_map<int,int> xF;
    unordered_map<int,int> yF;
    
    for(auto p:a){
        xF[p.x]+=1;
        yF[p.y]+=1;
    }
    
    int count=0;
    
    for(auto p:a){
        xF[p.x]-=1;
        yF[p.y]-=1;
        if(xF[p.x]==0 or yF[p.y]==0){
            xF[p.x]+=1;
            yF[p.y]+=1;
            continue;
        }
        count+=xF[p.x]*yF[p.y];
        xF[p.x]+=1;
        yF[p.y]+=1;
        
    }
    return count;
}



int main(){
    int N;
    cin>>N;
    int x,y;
    vector<Point> points;
    for(int i=0;i<N;i++){
        cin>>x>>y;
        points.push_back(Point(x,y));
    }
    cout<<countTriangles(points)<<endl;
}