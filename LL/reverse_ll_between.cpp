#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};


ListNode* createLL(vector<int>&arr){
    ListNode* head=new ListNode(arr[0]);
    ListNode* temp=head;
    int n=arr.size();
    for(int i=1;i<n;i++){
        temp->next=new ListNode(arr[i]);
        temp=temp->next;
    }
    return head;
}



void PrintLL(ListNode* head){
    ListNode* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=1;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(i!=left){
            prev=temp;
            temp=temp->next;
            i+=1;
        }

        ListNode* prevLeft=prev;
        ListNode* leftNode=temp;

        prev=temp;
        temp=temp->next;
        i+=1;

        while(i<=right){
            ListNode* nxtNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxtNode;
            i+=1;
        }

        if(prevLeft) prevLeft->next=prev;
        else head=prev;

        leftNode->next=temp;

        return head;


    }

int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   infile.ignore();
   while(t--){
       //C-1: for vector input: infile >> vec[i]; and the numbers in the input file should be space seperated
       //C-2: if number of elements in the vector is not provided(after infile of t do infile.ignore() to remove the nextLine character from the buffer)
       string line;
       getline(infile,line);
       stringstream ss(line);
       vector<int>arr;
       int num;
       while(ss>>num) arr.push_back(num);
       getline(infile,line);
       vector<int>postn;
       stringstream ss2(line);
       while(ss2>>num) postn.push_back(num);

       ListNode* head=createLL(arr);
       PrintLL(head);
       ListNode* newHead=reverseBetween(head,postn[0],postn[1]);
       cout<<"After between reversal: "<<endl;
       PrintLL(newHead);
   }
return 0;
}
