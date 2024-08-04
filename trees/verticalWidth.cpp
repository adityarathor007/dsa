class Solution
{
public:
    // Function to find the vertical width of a Binary Tree.
    void traversalCounter(Node *n, int c, int &mini, int &maxi)
    {
        if (!n)
        {
            return;
        }
        if (mini > c)
        {
            mini = c;
        }
        if (maxi < c)
        {
            maxi = c;
        }
        traversalCounter(n->left, c - 1, mini, maxi);
        traversalCounter(n->right, c + 1, mini, maxi);
    }

    int verticalWidth(Node *root)
    {
        // code here
        if (!root)
        { // edge case
            return 0;
        }
        int c = 0; // making root as 0 and going left and right
        int mini = 0;
        int maxi = 0;
        traversalCounter(root, c, mini, maxi);
        if (maxi != 0)
        {
            c += maxi;
        }
        if (mini != 0)
        {
            c += abs(mini);
        }
        return c + 1; // 1 extra added as we need to consider the count of root
    }
};