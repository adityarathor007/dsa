#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int d;
        Node* next;
        Node* back;
    Node(int d1){
        d=d1;
        next=nullptr;
        back=nullptr;
    }

    Node(int d1,Node* n1,Node* b1){
        d=d1;
        next=n1;
        back=b1;
    }

};


Node* convertToDLL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* curr=new Node(arr[i]);
        prev->next=curr;
        curr->back=prev;
        prev=prev->next;
    }

    return head;
}

void printLL(Node* head){
    while(head){
        cout<<head->d<<"->";
        head=head->next;
    }
    cout<<endl;
    
}


Node* removeHead(Node* head){
    if(!head) return nullptr;
    if(!head->next) return nullptr;
    Node* prev=head;
    head=head->next;
    
    
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;

    return head;
    

}


Node* removeTail(Node* head){
    if(!head or !head->next){
        return nullptr;
    }
    Node* tail=head;
    while(tail->next){
        tail=tail->next;
    }
    Node* prev=tail->back;
    prev->next=nullptr;
    tail->back=nullptr;

    delete tail;

    return head;
}

Node* deleteKthNode(Node* head,int k){
    Node* temp=head;
    int c=0;
    while (temp)
    {   
        c+=1;
        if(c==k){
            break;
        }
        temp=temp->next;
        /* code */

    }
    if(c<k){
        return nullptr;
    }

    Node* prev=temp->back;
    Node* front=temp->next;

    if(!prev and !front){
        return nullptr;
    }

    if(!prev){
        head=removeHead(head); }
    
    else if(!front){
        head=removeTail(head);
    }
    else{
        prev->next=front;
        temp->back=nullptr;
        temp->next=nullptr;
        front->back=prev;

        delete temp;
    }

    return head;
    
}


//giving the node which needs to be deleted 
void deleteNode(Node* temp){
    Node* prev=temp->back;
    Node* front=temp->next;
    if(!prev){
        temp->next=nullptr;
        front->back=nullptr;
        temp=front;
    }

    if(!front){
        prev->next=nullptr;
        temp->back=nullptr;
    }

    else{
        prev->next=front;
        front->back=prev;
        temp->next=nullptr;
        temp->back=nullptr;

    }

    delete(temp);

    return ;
}


Node* insertAtK(Node* head,int el,int k){
    if(!head){
        return new Node(el);
    }
    if(k==1){
        Node* n=new Node(el);
        n->next=head;
        head->back=n;
        head=n;
        return head;
    }

    int curr=0;
    Node* temp=head;
    while(temp){
        curr+=1;
        if(curr==k-1){
            Node* n=new Node(el,temp->next,temp);
            
            if(temp->next){
                temp->next=n;
                temp->next->back=n;

            }
          
            break;
        }
        temp=temp->next;
    }

    return head;
}


Node* reverseDLL(Node* head){
    
    
    // method 1 using swapping of next and 
        if(!head){
            return nullptr;
        }
        if(!head->next){
            return head;
        }
        Node* curr=head;
        Node* prev=nullptr;
        while(curr->next){
            // cout<<curr->d<<endl;
            prev=curr->back;
            curr->back=curr->next;
            curr->next=prev;
            
            curr=curr->back;
            
        }
        
        prev=curr->back;
        curr->back=curr->next;
        curr->next=prev;
        
        return curr;


        // method 2 using swapping of values
        
          // Node* i=head;
        // Node* tail=head;
        // int cnt=0;
        // while(tail->next){
        //     tail=tail->next;
        //     cnt+=1;
        // }
        
        // int c=0;
        
        // while(c<=cnt/2){
        //     swap(i->data,tail->data);
        //     i=i->next;
        //     tail=tail->prev;
        //     c+=1;
        // }

        // return head;
}






int main(){
    vector<int>arr{1,2,3,4};
    Node* head=convertToDLL(arr);
    printLL(head);

    // head=removeHead(head);
    // printLL(head);

    // head=removeTail(head);
    // printLL(head);

    // head=deleteKthNode(head,4);
    // printLL(head);


    // deleteNode(head->next);
    // printLL(head);


    // head=insertAtK(head,5,2);
    // printLL(head);

    head=reverseDLL(head);
    printLL(head);





}