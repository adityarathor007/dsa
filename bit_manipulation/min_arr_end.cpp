long long minEnd(int n, int x) {
        long long ans=x;
        long long temp=n-1;
        int i=0;
        while(temp){
            while((ans>>i)&1){
                i+=1; //not disturbing the bits of original n
            }
            if (temp & 1) {
                ans |= ((long long)1 << i);
            }

            temp >>= 1;
            i++;
        }

        return ans;
    }
