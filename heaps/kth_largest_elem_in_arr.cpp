 //finding without sorting
 
 int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num:nums){
            pq.push(num);
            if(pq.size()>k){
                cout<<pq.top()<<endl;
                pq.pop();
            }
        }
        return pq.top();