int findDuplicate(vector<int>& nums) {
        int hare=nums[0];
        int tortoise=nums[0];
        while(true){
            tortoise=nums[tortoise];
            hare=nums[nums[hare]];
            if(hare==tortoise) break;
        }


        int ptr1=nums[0];
        int ptr2=tortoise;
        while(ptr1!=ptr2){
            ptr1=nums[ptr1];
            ptr2=nums[ptr2];
        }
        return ptr1;
    }
