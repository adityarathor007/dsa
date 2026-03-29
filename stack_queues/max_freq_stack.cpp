class FreqStack {
    unordered_map<int,int>freq; //freq for each element
    unordered_map<int,stack<int>>group; //groups based on freq
    int max_freq=0;
public:
    FreqStack() {

    }

    void push(int val) {
        freq[val]+=1;
        int f=freq[val];
        if(f>max_freq) max_freq=f;
        group[f].push(val);
    }

    int pop() {
        int val=group[max_freq].top();
        freq[val]-=1;
        group[max_freq].pop();
        if(group[max_freq].empty()) max_freq--;
        return val;
    }
};
