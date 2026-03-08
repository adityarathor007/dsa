 //finding without sorting

 int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq; //min_heap

        for(int num:nums){
            pq.push(num);
            if(pq.size()>k){
                // cout<<pq.top()<<endl;
                pq.pop(); //removing the smallest element which would go beyond the kth position if sorted from large to small
            }
        }

    return pq.top();
 }
