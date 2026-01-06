struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }

};

class LRUCache {
    unordered_map<int,Node*>mp;
    Node* head=nullptr,*tail=nullptr;
    int cap=0;

    void moveToStart(Node* node){
        if(node==head) return;

        Node* prevNode=node->prev;
        Node* nxtNode=node->next;

        prevNode->next=nxtNode;
        if(nxtNode) nxtNode->prev=prevNode;
        else tail=prevNode;

        head->prev=node;
        node->next=head;

        // cout<<"Before: "<<head->val<<" "<<" After: "<<node->val<<endl;
        head=node;



    }

    void addNode(Node* node){
        if(!head){
            head=node;
            tail=node;
        }
        else{
            head->prev=node;
            node->next=head;
        }

        head=node;
        // cout<<head->val<<endl;
    }

    int removeNode(){
        int key=tail->key;
        Node* prevNode=tail->prev;
        prevNode->next=nullptr;
        tail=prevNode;
        return key;
    }

public:
    LRUCache(int capacity) {
        cap=capacity;
    }

    int get(int key) {
        if(!mp.count(key)) return -1;
        Node* node=mp[key];
        moveToStart(node);
        return node->val;
    }

    void put(int key, int value) {
        if(mp.count(key)){
            Node* node=mp[key];
            node->val=value;
            moveToStart(node);
        }
        else{
            Node* node=new Node(key,value);
            addNode(node);
            mp[key]=node;
            if(mp.size()>cap){
                int rk=removeNode();
                mp.erase(rk);
            }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
