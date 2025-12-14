/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* recConstruct(int x1,int x2,int y1,int y2,vector<vector<int>>&grid){
        Node* node=new Node();
        int cnt=0;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                cnt+=grid[i][j];
            }
        }
        // cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<" "<<cnt<<endl;
        int n=(x2-x1+1);
        if(cnt==0 or cnt==n*n){
            // cout<<"isLeaf"<<endl;
            if(cnt!=0) node->val=true;
            node->isLeaf=1;
            return node;
        }
        node->val=true;
        node->topLeft=recConstruct(x1,x1+n/2-1,y1,y1+n/2-1,grid);
        node->topRight=recConstruct(x1,x1+n/2-1,y1+n/2,y2,grid);
        node->bottomLeft=recConstruct(x1+n/2,x2,y1,y1+n/2-1,grid);
        node->bottomRight=recConstruct(x1+n/2,x2,y1+n/2,y2,grid);

        return node;


    }

    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return recConstruct(0,n-1,0,n-1,grid);
    }
};
