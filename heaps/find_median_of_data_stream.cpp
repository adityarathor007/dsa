priority_queue<int>left_half;
    priority_queue<int,vector<int>,greater<int>>right_half;

    MedianFinder() {

    }

    void addNum(int num) {
        int lsize=left_half.size();
        int rsize=right_half.size();
        if(lsize==rsize){
            if(lsize==0) left_half.push(num);
            else if(left_half.top()>num) left_half.push(num);
            else right_half.push(num);
        }
        else if(lsize>rsize){
            if(left_half.top()>num){
                right_half.push(left_half.top());
                left_half.pop();
                left_half.push(num);
            }
            else right_half.push(num);
        }
        else{
            if(right_half.top()<num){
                left_half.push(right_half.top());
                right_half.pop();
                right_half.push(num);
            }
            else left_half.push(num);
        }
    }

    double findMedian() {
        int ls=left_half.size();
        int rs=right_half.size();
        if(ls==rs) return ((double)(left_half.top()+right_half.top()))/2;
        else if(ls>rs) return left_half.top();
        return right_half.top();
    }
