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

class DLL{
Node* head=nullptr,*tail=nullptr;
public:
    void addNode(Node* cn){
        if(head) head->prev=cn;
        cn->next=head;
        head=cn;
        if(!tail) tail=head;
    }

    void markRU(Node* cn){
        if(cn==head) return;

        Node* nxtNode=cn->next;
        Node* prevNode=cn->prev;

        if(nxtNode) nxtNode->prev=prevNode;
        if(prevNode) prevNode->next=nxtNode;

        if(cn==tail) tail=prevNode;
        head->prev=cn;
        cn->next=head;
        head=cn;
    }

    int removeLRU(){
        Node* prevNode=tail->prev;
        prevNode->next=nullptr;
        int rk=tail->key;
        tail=prevNode;
        return rk;
    }
};

class LRUCache {
    int cap;
    unordered_map<int,Node*>mp;
    DLL dll=DLL();
public:
    LRUCache(int capacity) {
        cap=capacity;
    }

    int get(int key) {
        if(!mp.count(key)) return -1;
        Node* cn=mp[key];
        dll.markRU(cn);
        return cn->val;
    }

    void put(int key, int value) {
        if(!mp.count(key)){
            Node* cn=new Node(key,value);
            dll.addNode(cn);
            mp[key]=cn;
        }
        else{
            Node* cn=mp[key];
            cn->val=value;
            dll.markRU(cn);
        }
        if(mp.size()>cap){
            int rk=dll.removeLRU();
            mp.erase(rk);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
