#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int>pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(1);

    cout<<"element at the top "<<pq.top()<<endl;
    pq.pop();

    cout<<"element at the top "<<pq.top()<<endl;

    cout<<"the size of pq is "<<pq.size()<<endl;

    // for creating min heap
    priority_queue<int,vector<int>,greater<int>>min_heap;


    return 0;
}
