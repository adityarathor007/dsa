#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    node *tail = head; // new variable tail which will mark the end of the linkedlist
    while (tail->next != NULL)
    { // stopping before crossing the last node
        tail = tail->next;
    }

    node *n = new node(data);
    tail->next = n;

    return;
}

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
    return;
}

node *merge(node *a, node *b)
{
    if (a == NULL)
    { // if a reached the null then return the head of the remaining array
        return b;
    }

    else if (b == NULL)
    {
        return a;
    }

    node *c;

    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }

    return c;
}

node *removeAllDuplicates(node *head)
{
    if (!head)
        return NULL;

    std::stack<node *> s;
    node *curr = head;
    int cv = curr->data;
    s.push(curr);
    curr = curr->next;

    while (curr)
    {
        if (curr->data != cv)
        {
            cv = curr->data;
            s.push(curr);
        }
        else
        {
            s.pop();
        }
        curr = curr->next;
    }

    node *e = NULL;
    if (!s.empty())
    {
        e = s.top();
        s.pop();
        e->next = NULL;
    }

    node *cu = e;
    while (!s.empty())
    {
        cu = s.top();
        s.pop();
        cu->next = e;
        e = cu;
    }

    return cu;
}

int main()
{
    node *a = NULL;
    insertAtTail(a, 1);
    insertAtTail(a, 2);
    insertAtTail(a, 2);
    insertAtTail(a, 2);
    insertAtTail(a, 3);
    removeAllDuplicates(a);
    printLL(a);

}