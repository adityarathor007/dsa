 int getSum(int a, int b) {
        if(b==0) return a;
        int sum_wo_carry=a^b;
        int carry=(a&b)<<1; //as the carry affects the next bit
        return getSum(sum_wo_carry,carry);
    }
