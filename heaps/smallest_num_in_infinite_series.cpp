//Lazy addition of numbers to the set

    int currentSmallest; //smallest number that has not been used yet
    priority_queue<int,vector<int>,greater<int>>pq; //min heap to store the numbers that were popped but are added back again
    unordered_set<int>st; //just to track what numbers are there inside pq so that we don't add duplicates
    
    SmallestInfiniteSet(){
     currentSmallest=1;     
    }
    int popSmallest() {
        int val;
        if(!pq.empty()){ //These are previously "added back" numbers.after being popped
            val=pq.top();
            pq.pop();
            st.erase(val);
        }
        else{ //No numbers have been added back, so the smallest number is the next in the infinite sequence
            val=currentSmallest; 
            currentSmallest+=1;
        }
        return val;

    }
    
    void addBack(int num){ 
        if(num>=currentSmallest or st.find(num)!=st.end()) return;

        //Only add back numbers that were previously popped and are less than currentSmallest
        pq.push(num);
        st.insert(num);
    }   