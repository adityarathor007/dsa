w#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    Node(){
        left=NULL;
        right=NULL;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(int value)
    {
        Node *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (value >> i) & 1;
            if (bit == 0)
            {
                if (curr->left == NULL)
                {
                    curr->left = new Node();
                }
                curr = curr->left;
            }
            else
            {
                if (curr->right == NULL)
                {
                    curr->right = new Node();
                }
                curr = curr->right;
            }
        }
    }

    int max_xor_helper(int value)
    {
        Node *curr = root;
        int c_ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (value >> i) & 1;
            if (bit == 0)
            {
                if (curr->right != NULL)
                {
                    curr = curr->right;
                    c_ans += (1 << i);
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->left != NULL)
                {
                    curr = curr->left;
                    c_ans += (1 << i);
                }
                else
                {
                    curr = curr->right;
                }
            }
        }

        return c_ans;
    }
};

int max_xor_pair(vector<int> arr)
{
    // implement the max xor pair function
    int max_value = INT_MIN;
    Trie t;
    for (auto x : arr)
    {

        t.insert(x);
        int value = t.max_xor_helper(x);
        max_value = max(max_value, value);
    }
    return max_value;
}


int main(){
    vector<int> arr={1};
    cout<<max_xor_pair(arr)<<endl;
}