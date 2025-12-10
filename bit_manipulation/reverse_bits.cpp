int reverseBits(int n) {
        int ans=0;

        for(int i=0;i<32;i++){
            int bit=(n>>i)&1;
            ans=ans+pow(2,31-i)*bit;
        }

        for(int i=0;i<32;i++){
            int bit=(ans>>i)&1;
        }
        return ans;
    }
