/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>node_to_cnode;

    Node* copyRandomList(Node* head) {
        //M1: using hashmap to keep track of orig_node and copy_node
        // Node* temp=head;
        // Node* prev_dc=NULL;
        // Node* dup_head=NULL;

        // if(!head) return head;

        // while(temp){
        //     Node* dc_node=new Node(temp->val);
        //     if(prev_dc) prev_dc->next=dc_node;
        //     else dup_head=dc_node;
        //     prev_dc=dc_node;

        //     node_to_cnode[temp]=dc_node;
        //     temp=temp->next;
        // }


        // temp=head;
        // Node* copy_temp=dup_head;

        // while(temp){
        //     if(temp->random){
        //         Node* crandom_node=node_to_cnode[temp->random];
        //         copy_temp->random=crandom_node;
        //     }

        //     temp=temp->next;
        //     copy_temp=copy_temp->next;
        // }


        // return dup_head;


        // M2: placing the nodes in between
        // placing the node in between
        Node* temp=head;
        while(temp){

            Node* dup_node=new Node(temp->val);
            Node* nxtNode=temp->next;
            temp->next=dup_node;
            dup_node->next=nxtNode;
            temp=nxtNode;

        }



        //  connecting the random pointer for the duplicate nodes
        temp=head;
        while(temp){
            if(temp->random!=NULL){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;

        }



        // connecting the next using extraction of deepcopy
        Node* dummyNode=new Node(-1);
        temp=head;
        Node* res=dummyNode;

        while(temp){
            res->next=temp->next;

            // restoring the original list
            temp->next=temp->next->next;

            temp=temp->next;
            res=res->next;

        }


        return dummyNode->next;
    }
};
