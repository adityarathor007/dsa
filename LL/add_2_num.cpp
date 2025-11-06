#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x): val(x),next(nullptr) {}
    ListNode(int x, ListNode *next): val(x),next(next) {}
};

ListNode* createLL(vector<int>arr){
    ListNode* head=new ListNode(arr[0]);
    ListNode *t1=head;
    for(int i=1;i<arr.size();i++){
        t1->next=new ListNode(arr[i]);
        t1=t1->next;
    }
    return head;
}





 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *temp1=l1,*temp2=l2;
    ListNode *result=new ListNode();
    ListNode *dummy=result;
    int carry=0;

    while(temp1 || temp2 || carry){
        int sum=carry+(temp1?temp1->val:0)+(temp2?temp2->val:0);
        carry=sum/10;
        dummy->next=new ListNode(sum%10);
        dummy=dummy->next;
        if(temp1){
            temp1=temp1->next;
        }
        if(temp2){
            temp2=temp2->next;
        }
    } 
    return result->next;
}


void printLL(ListNode* head){
    ListNode *temp=head;
    while(temp){
        cout<<temp->val<<", ";
        temp=temp->next;
    }
    cout<<endl;
    return ;
}


int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   infile.ignore();
   while(t--){
       //C-1: we have the arr size for vector input: infile >> vec[i]; and the numbers in the input file should be space seperated
       //C-2: if number of elements in the vector is not provided(after infile of t do infile.ignore() to remove the nextLine character from the buffer)
       string line;
       getline(infile,line);
       stringstream ss(line);
       vector<int>arr1;       
       int num1;               
       while(ss>>num1) arr1.push_back(num1);
       line="";
       vector<int>arr2;
       getline(infile,line);
       stringstream ss2(line);
       int num2;
       while(ss2>>num2) arr2.push_back(num2);

    //    for(int num:arr1) cout<<num<<", ";
    //    cout<<endl;
    //    for(int num:arr2) cout<<num<<", ";
    //    cout<<endl;

        ListNode *h1=createLL(arr1);
        ListNode *h2=createLL(arr2);

        ListNode *r=addTwoNumbers(h1,h2);
        printLL(r);            
   }
return 0;
}

