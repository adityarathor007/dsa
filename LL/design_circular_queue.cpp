struct Node{
    int val;
    Node* next=nullptr;
    Node(int v){
        val=v;
    }
};

class MyCircularQueue {
    int cs=0;
    int cap;
    Node* head,*tail;
public:
    MyCircularQueue(int k) {
        head=nullptr;
        tail=nullptr;
        cs=0;
        cap=k;
    }

    bool enQueue(int value) {
        if(isFull()) return false;
        cs+=1;
        Node* node=new Node(value);
        if(tail) tail->next=node;
        tail=node;
        if(!head) head=tail;
        return true;
    }

    bool deQueue() {
        if(isEmpty()) return false;
        cs-=1;
        Node* nxtNode=head->next;
        if(tail==head) tail=nxtNode;
        head=nxtNode;
        return true;
    }

    int Front() {
        if(isEmpty()) return -1;
        return head->val;
    }

    int Rear() {
        if(isEmpty()) return -1;
        return tail->val;
    }

    bool isEmpty() {
        return cs==0;
    }

    bool isFull() {
        return cs==cap;
    }
};
