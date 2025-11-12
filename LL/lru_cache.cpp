struct Node{
    int key;
    int val;
    Node* next=NULL;
    Node* prev=NULL;

    Node(int k,int value){
        key=k;
        val=value;
    }

};

class LRUCache {
    unordered_map<int,Node*>cache;
    int max_cap;
    Node* head=NULL;
    Node* tail=NULL;
public:
    void updateLRU(Node* node){
        if(tail==node) return ;

        Node* prevNode=node->prev;
        Node* nxtNode=node->next;

        nxtNode->prev=prevNode;
        if(node==head) head=nxtNode;
        else prevNode->next=nxtNode;

        tail->next=node;
        node->prev=tail;
        node->next=NULL;
        tail=node;
        // cout<<tail->key<<endl;
    }

    Node* addNode(int key,int value){
        Node* node=new Node(key,value);

        if(!head){
            head=node;
            tail=head;
        }
        else{
            tail->next=node;
            node->prev=tail;
            tail=node;
        }

        return tail;
    }

    int removeLRUNode(){
        int lru_key=head->key;
        Node* nxtNode=head->next;
        // delete(head);
        head=nxtNode;
        return lru_key;
    }


    LRUCache(int capacity) {
        max_cap=capacity;
        tail=head;
    }

    int get(int key) {
        if(cache.find(key)!=cache.end()){
            updateLRU(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(cache.find(key)==cache.end()){
            Node *nodePtr=addNode(key,value);
            cache[key]=nodePtr;
        }

        else{
            cache[key]->val=value;
            updateLRU(cache[key]);
        }


        if(cache.size()>max_cap){
            int lru_key=removeLRUNode();
            // cout<<"key that is removed: "<<lru_key<<endl;
            cache.erase(lru_key);
        }
    }
};

