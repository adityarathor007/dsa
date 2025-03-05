#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int data;
	struct Node *next;
	Node(int x){
		data=x;
		next=NULL;
	}

};


void printLL(Node *head){
	if(head!=NULL){
		Node* temp=head;
		while(temp->next!=head){
			cout<<temp->data<<",";
			temp=temp->next;

		}
		cout<<temp->data<<endl;
		
		
	}
	else{
		cout<<"Empty"<<endl;
	}


}

Node* reverse(Node* head) {
        // code here
         // reversing linked list
        Node* temp=head->next;
        Node* prev=head;
        while(temp->next!=head){
//	    cout<<temp->data<<endl;
            Node* nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
//	cout<<temp->data<<endl;
	temp->next=prev;
        head->next=temp;
        head=temp;
        
	cout<<head->next->data<<endl;        
        return head;
}




Node* deleteNode(Node* head, int key) {
        // code here
        Node* temp=head;
        Node* prev=temp;
        if(temp->data==key){
            while(temp->next!=head){
                temp=temp->next;
            }
            head=head->next;
            temp->next=head;
        }
        else{
            
            temp=temp->next;
            while(temp!=head){
            if(temp->data==key){
                prev->next=temp->next;
                temp->next=NULL;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
           
        }
        
        
       
        return head;
       
    }




int main(){


	vector<int>arr{10,7,8,4,6};
	int key=10;
	Node* head=new Node(arr[0]);
	Node* tail=head;
	for(int i=1;i<arr.size();i++){
		tail->next=new Node(arr[i]);
		tail=tail->next;
	}
	tail->next=head;
	head=deleteNode(head,key);
//	cout<<head->next->data<<endl;
	head=reverse(head);
//	cout<<head->data<<endl;

	printLL(head);

}
