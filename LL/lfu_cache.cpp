struct Node{
    int key;
    int val;
    int freq;
    Node* next,*prev;
    Node(int key,int value,int freq){
        this->key=key;
        this->val=value;
        this->freq=freq;
        next=nullptr;
        prev=nullptr;
    }
};

class DLL{

public:
    Node* head,*tail;
    void addNode(Node* node){
        if(head) head->prev=node;
        node->next=head;
        head=node;
        if(!tail) tail=head;
    }

    void removeNode(Node* node){
        Node* prevNode=node->prev;
        Node* nxtNode=node->next;
        if(prevNode) prevNode->next=nxtNode;
        if(nxtNode) nxtNode->prev=prevNode;

        if(node==head) head=node->next;
        if(node==tail) tail=node->prev;

        // if(head) cout<<"current head: "<<head->val<<endl;

        node->prev=nullptr;
        node->next=nullptr;
    }

    int removeLRU(){
        Node* node = tail;
        int key = node->key;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete node;
        return key;
    }


    bool isEmpty(){
        // if(head) cout<<head->val<<endl;
        return head==nullptr;
    }
};

class LFUCache {
    int min_freq=0;
    int cap;
    unordered_map<int,Node*>keyMap;
    unordered_map<int,DLL>cntMap;

    void addNode(int key,int value){
        min_freq=1;
        Node* cn=new Node(key,value,1);
        cntMap[min_freq].addNode(cn);
        keyMap[key]=cn;
    }

    void updateDLL(Node* node){
        // cout<<"updated node key: "<<node->key<<endl;
        int cf=node->freq;
        cntMap[cf].removeNode(node);
        if(cntMap[cf].isEmpty()){
            cntMap.erase(cf);
            if(cf==min_freq) min_freq+=1;
        }
        // cout<<"min freq: "<<min_freq<<endl;

        node->freq=cf+1;
        cntMap[cf+1].addNode(node);
    }

    void removeLFUNode(){
        DLL& min_dll = cntMap[min_freq];  //else any modification wont affect the actual dll
        int rk=min_dll.removeLRU();
        // cout<<"key to be removed from lfu logic: "<<rk<<endl;
        keyMap.erase(rk);
        if(min_dll.isEmpty()){
            cntMap.erase(min_freq);
            min_freq=1; //because next a new node will come
        }
    }

public:
    LFUCache(int capacity) {
        cap=capacity;
    }

    int get(int key) {
        if(!keyMap.count(key)) return -1;
        Node* node=keyMap[key];
        updateDLL(node);
        return node->val;
    }

    void put(int key, int value) {
        if(keyMap.count(key)){
            Node* node=keyMap[key];
            node->val=value;
            updateDLL(node);
        }
        else{
            if(keyMap.size()+1>cap){
                removeLFUNode();
            }
            addNode(key,value);
        }
    }
};
