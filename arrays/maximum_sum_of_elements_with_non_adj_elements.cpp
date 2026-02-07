const long long inf = 1e18;

struct Node{
    Node *ln=nullptr,*rn=nullptr;
    unsigned l,r;
    long long selected[2][2];

    Node(vector<int>&nums,int lo,int hi){
        l=lo;
        r=hi;
        if(l<r){
            int mid=(l+r)/2;
            ln=new Node(nums,l,mid);
            rn= new Node(nums,mid+1,r);

            combine();
        }
        else{
            selected[0][0]= 0;
            selected[0][1] = -inf;
            selected[1][0] = -inf;
            selected[1][1] = nums[l];
        }
    }

    void combine(){
        selected[0][0]=max(ln->selected[0][0]+rn->selected[0][0],max(ln->selected[0][1] + rn->selected[0][0], ln->selected[0][0] + rn->selected[1][0]));
        selected[1][0]=max(ln->selected[1][0]+rn->selected[0][0],max(ln->selected[1][1] + rn->selected[0][0], ln->selected[1][0] + rn->selected[1][0]));
        selected[0][1]=max(ln->selected[0][0]+rn->selected[0][1],max(ln->selected[0][1] + rn->selected[0][1], ln->selected[0][0] + rn->selected[1][1]));
        selected[1][1]=max(ln->selected[1][0]+rn->selected[0][1],max(ln->selected[1][1] + rn->selected[0][1], ln->selected[1][0] + rn->selected[1][1]));

    }

    void update(int i,long long x){
        if(i<l || r<i) return;

        if(l==r){
            selected[0][0]=0;
            selected[1][1] = x;
            return;
        }

        ln->update(i,x);
        rn->update(i,x);

        combine();

    }

};


class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        Node segmentTree(nums,0,nums.size()-1);
        long long res=0;
        int mod=1e9+7;

        for(auto& query:queries){
            segmentTree.update(query[0],query[1]);
            res+=max(segmentTree.selected[0][0],max(segmentTree.selected[0][1],max(segmentTree.selected[1][0],segmentTree.selected[1][1])));
            res%=mod;
        }

        return res;


    }
};
