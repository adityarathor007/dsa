#include <iostream>
#include <set>
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

class Compare{
    public:
    bool operator()(const Point A, const Point B){
        if(A.x==B.x){
            return A.y<B.y;
        }
        return A.x<B.x;
    }
};

int CountRectangles(vector<Point>a){
    set<Point,Compare> ptable;
    
    
    for(auto p:a){
        ptable.insert(p);
    }
    
    int n=a.size();
    int c=0;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].x==a[j].x or a[i].y==a[j].y){
                continue;
            }
            if(ptable.find(Point(a[i].x,a[j].y))!=ptable.end() and ptable.find(Point(a[j].x,a[i].y)) !=ptable.end()){
                c+=1;
            }
        }
    }
    return c/2;
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
    cout<<CountRectangles(points)<<endl;
}