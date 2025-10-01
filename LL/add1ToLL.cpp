int helper(Node* curr){
        if(curr==nullptr){
            return 1;
        }
        int carry=helper(curr->next);
        int num=curr->data;
        num+=carry;
        if(num==10){
            curr->data=0;
            return 1;
        }
        curr->data=num;
        return 0;

    }

    Node* addOne(Node* head) {
        // Your Code here
        int carry=helper(head);

        if(carry==1){
            Node* newHead=new Node(1);
            newHead->next=head;
            return newHead;
        }
        return head;

    }
