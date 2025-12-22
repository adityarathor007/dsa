string shortestPalindrome(string s) {
        // using the robin karp algorithm (finding the shortest prefix palindrome which is also a suffix so that we dont need to add more chars)
        long long prefix_hash=0,suffix_hash=0;
        int base=31,last_index=0;
        long long power=1,mod=1e9+7;
        int n=s.size();
        if(n==0) return s;
        for(int i=0;i<n;i++){
            prefix_hash=(prefix_hash*base+s[i])%mod;
            suffix_hash=(suffix_hash+s[i]*power)%mod;
            power=(power*base)%mod;
            if(prefix_hash==suffix_hash) last_index=i;
        }

        if(last_index==n-1) return s;
        string rev_add=s.substr(last_index+1,n-last_index+1);
        reverse(rev_add.begin(),rev_add.end());
        return rev_add+s;
    }
