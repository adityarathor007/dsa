#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr) {}
}


struct Compare {
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;  //min-heap
    }
}


ListNode* mergeLists(vector<ListNode*> &lists){

    priority_queue<ListNode*,vector<ListNode*>,Compare>minHeap;

    for(auto list:lists){
        if(list) pq.push(list);
    }

    ListNode dummy(0);
    ListNode* tail=&dummy;

    while(!pq.empty()){
        ListNode* smallest=pq.top();
        pq.pop();

        tail->next=smallest;
        tail=tail->next;

        if(smallest->next){
            pq.push(smallest->next);
        }
    }

    return dummy.next;




}
