 ListNode* mergeSortedList(ListNode* h1, ListNode* h2){
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        while(h1 and h2){
            if(h1->val<=h2->val){
                temp->next=h1;
                h1=h1->next;
            }
            else{
                temp->next=h2;
                h2=h2->next;
            }
            temp=temp->next;
        }
        if(h1) temp->next=h1;
        if(h2) temp->next=h2;
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>&lists){
        if(lists.size()==0) return nullptr;
        while(lists.size()>1){
            vector<ListNode*>temp;
            for(int i=0;i<lists.size();i+=2){
                ListNode* h1=lists[i];
                ListNode* h2=i+1<lists.size()?lists[i+1]:nullptr;
                temp.push_back(mergeSortedList(h1,h2));
            }
            lists=move(temp);
        }
        return lists[0];
    }
