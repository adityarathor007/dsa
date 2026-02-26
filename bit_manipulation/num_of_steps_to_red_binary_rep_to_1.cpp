int numSteps(string s) {
        int n=s.size();
        int steps=0,carry=0;
        for(int i=n-1;i>0;i--){
            int bit=s[i]&1;
            steps+=1+(bit^carry); //if odd(set bit) then add extra as it would require to shift also after adding 1
            carry|=bit;
        }
        return steps+carry;
    }
