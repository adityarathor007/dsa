class NumArray {
    vector<int>tree;
    int n;

    void build(int idx,int l,int r,vector<int>&nums){
        if(l==r){
            tree[idx]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*idx+1,l,mid,nums);
        build(2*idx+2,mid+1,r,nums);
        tree[idx]=tree[2*idx+1]+tree[2*idx+2];
    }

    void updateTree(int idx,int l,int r,int pos,int val){
        if(l==r){
            tree[idx]=val;
            return;
        }

        int mid=(l+r)/2;
        if(pos<=mid) updateTree(2*idx+1,l,mid,pos,val);
        else updateTree(2*idx+2,mid+1,r,pos,val);

        tree[idx]=tree[2*idx+1]+tree[2*idx+2];
    }

    int query(int idx,int l,int r,int ql,int qr){
        if(ql>r || qr<l) return 0; //no overlap

        if(ql<=l and r<=qr) return tree[idx]; //total overlap

        // partial overlap
        int mid=(l+r)/2;
        return query(2*idx+1,l,mid,ql,qr)+query(2*idx+2,mid+1,r,ql,qr);
    }


public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(4*n);
        build(0,0,n-1,nums);
    }

    void update(int index, int val) {
        updateTree(0,0,n-1,index,val);
    }

    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};
