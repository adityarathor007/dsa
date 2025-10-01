void deleteAllOccurrences(Node** head_ref, int k) {
    Node* p0 = *head_ref;
    Node* p1 = nullptr;

    while (p0 != nullptr) {
        if (p0->data == k) {
            Node* nxtpost = p0->next;

            // If deleting head node
            if (p1 == nullptr) {
                *head_ref = nxtpost; // update head_ref directly
                if (nxtpost != nullptr) {
                    nxtpost->prev = nullptr;
                }
                delete p0;
                p0 = nxtpost;
            } else {
                // Not head
                p1->next = nxtpost;
                if (nxtpost != nullptr) {
                    nxtpost->prev = p1;
                }
                delete p0;
                p0 = nxtpost;
            }
        } else {
            p1 = p0;
            p0 = p0->next;
        }
    }
}
