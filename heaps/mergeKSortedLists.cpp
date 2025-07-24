#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr) {}
};

struct Compare {
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;  //min-heap
    }
};


ListNode* mergeLists(vector<ListNode*> &lists){

    priority_queue<ListNode*,vector<ListNode*>,Compare>minHeap;   //storing the pointers of the linkedlist

    for(auto list:lists){
        if(list) minHeap.push(list);
    }

    ListNode dummy(0);
    ListNode* tail=&dummy;

    while(!minHeap.empty()){
        ListNode* smallest=minHeap.top();
        minHeap.pop();

        tail->next=smallest;
        tail=tail->next;    

        if(smallest->next){
            minHeap.push(smallest->next);
        }
    }

    return dummy.next;




}
