class StockSpanner {
    stack<pair<int,int>>st;
public:
    StockSpanner() {

    }

    int next(int price) {
        if(st.empty()){
            st.push({price,1});
            return 1;
        }

        int cnt=1;
        while(!st.empty() and st.top().first<=price){
            auto [_,prev_cnt]=st.top();
            st.pop();
            cnt+=prev_cnt;
        }

        st.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
