//Lazy addition of numbers to the set

    int currentSmallest; //smallest number that has not been used yet
    priority_queue<int,vector<int>,greater<int>>pq; //min heap to store the numbers that were popped but are added back again
    unordered_set<int>st; //just to track what numbers are there inside pq so that we don't add duplicates

    SmallestInfiniteSet(){
     currentSmallest=1;
    }
    
    int popSmallest() {
        if(!pq.empty()){
            int min_e=pq.top();
            pq.pop();
            st.erase(min_e);
            return min_e;

        }
        return current++;

    }

    void addBack(int num){
        //Only add back numbers that were previously popped and are less than currentSmallest
        if(num<current and !st.count(num)){
            pq.push(num);
            st.insert(num);
        }
    }
