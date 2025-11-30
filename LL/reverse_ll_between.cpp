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



ListNode* reverseHelper(ListNode* &head,int left,int right, ListNode* &endNode){
    ListNode* prev=endNode;
    ListNode* curr=head;
    int i=left;
    while(i!=right+1){
        ListNode* nxtNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxtNode;
        i+=1;
    }

    return prev; //return the starting Node of the reversed part
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(left==right) return head;
    int i=1;
    ListNode *startNode=NULL,*endNode=NULL;
    ListNode* temp=head;
    while(temp){
        if(i==left-1) startNode=temp;
        if(i==right+1) endNode=temp;
        temp=temp->next;
        i+=1;
    }

    i=1;
    temp=head;
    while(i!=left){
        temp=temp->next;
        i+=1;
    }

    ListNode* revhead=reverseHelper(temp,left,right,endNode);
    if(startNode) startNode->next=revhead;
    else{
        return revhead;
    }
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
