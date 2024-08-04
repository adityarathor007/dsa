#include <iostream>
#include <vector>
using namespace std;


class node{
    public:
        int data;
        node* next;
        
        node(int d){ //constructor function
            data=d;  
            next=NULL;
        }
};

void insertAtHead(node* &head,int data){
    if(head==NULL){ //if LL is empty
        head=new node(data);
        return;
    }

        node* n = new node(data);
        n->next=head; //pointing the new node where head was pointing
        head=n; //making this node as the head

    return;
};

void insertInMiddle(node* &head,int data,int pos){
    if(pos==0){ //we have to update the header
        head=new node(data);
        return;
    }
    node* n = new node(data);
    node* current=head;
    int i=1;
    while(i!=pos){
        current=current->next;
        i++;
    }
    n->next=current->next;
    current->next=n;
}



void printLL(node* head){  //passing the head as a copy as passed by value so wont change the actual head
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}


node* convArrToLL(vector<int>&arr){
    node* head=new node(arr[0]);
    node* it=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        it->next=temp;
        it=it->next;
    }

    return head;
}


node* delKthElement(node* head,int k){
    if(!head) return head;
    node* temp=head;
    if(k==1){
        head=head->next;
        free(temp);
        return head;
    }
    int c=0;
    node* prev=NULL;
    while(temp){
        c++;
        if(c==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;

    }
    return head;

}


node* delElementByVal(node* head,int el){
    if(!head) return head;
    node* temp=head;
    if(temp->data==el){
        head=head->next;
        free(temp);
        return head;
    }
    node* prev=NULL;
    while(temp){
        if(temp->data==el){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;

    }
    return head;

}

node* insertAtKth(node* head,int el,int k){
    if(head==NULL){
        if(k==1){
            return new node(el);
        }
    }

    node* temp=head;
    if(k==1){
        temp=new node(el);
        temp->next=head;
        return temp;
    }

    int cnt=0;

    while(temp){
        cnt++;
        cout<<cnt<<endl;
        if(cnt==k-1){
            node* nxt=temp->next;
            temp->next=new node(el);
            temp->next->next=nxt;
            break;
        }
        temp=temp->next;
    }

    return head;

}


node* insertElBeforeX(node* head,int el,int x){
    if(!head) return NULL;
    if(x==head->data){
        node* temp=new node(el);
        temp->next=head;
        return temp;
    }
    node* temp=head;
    // node* prev=NULL;
    while(temp->next){
        if(temp->next->data==x){
            node*t=temp->next;
            temp->next=new node(el);
            temp->next->next=t;
            break;
        }
        temp=temp->next;
    }

    return head;
}

int main(){
    node* head=NULL;
    // insertAtHead(head, 10);
    // insertAtHead(head,20);
    // insertAtHead(head,5);
    // insertAtHead(head,0);
    // insertAtHead(head,30);
    // insertAtHead(head,40);
    // insertInMiddle(head, 122, 6);

    vector<int> arr{1,2,3,4,5};
    node* h=convArrToLL(arr);
    printLL(h);
    // int k=3;
    // h=delKthElement(h,k);
    // printLL(h);
    // int el=3;
    // h=delElementByVal(h,el);

    // h=insertAtKth(h,10,2);
    // printLL(h);
    
    //printing the LL
    h=insertElBeforeX(h,10,1);
    printLL(h);
    
    
    
}