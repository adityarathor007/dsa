int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        int MOD = 1e9 + 7;
        int maxInv = n*(n-1)/2;

        // Map requirements for quick lookup: length -> required_inversions
        map<int, int> reqMap;
        for (auto& req : requirements) {
            reqMap[req[0] + 1] = req[1];
        }

        // dp[len][inv_cnt]
        vector<vector<long long>> dp(n + 1, vector<long long>(maxInv + 1, 0));

        // Base case: a permutation of length 1 always has 0 inversions
        if (reqMap.count(1) && reqMap[1] != 0) return 0;
        dp[1][0] = 1;

        for (int len = 2; len <= n; len++) {
            long long currentSum = 0;
            for (int inv = 0; inv <= maxInv; inv++) {
                // Add the new possible ways
                currentSum = (currentSum + dp[len - 1][inv]) % MOD;

                // Slide the window: if inv >= len, we remove the contribution
                // of the element that is now out of reach
                if (inv >= len) {
                    currentSum = (currentSum - dp[len - 1][inv - len] + MOD) % MOD;
                }

                dp[len][inv] = currentSum;
            }

            // Apply requirement constraint for the current prefix length
            if (reqMap.count(len)) {
                int target = reqMap[len];
                for (int inv = 0; inv <= maxInv; inv++) {
                    if (inv != target) dp[len][inv] = 0;
                }
            }
        }

        return dp[n][reqMap[n]]; //the last one because for making the length n the previous contribution of arrays with invalid inversion count was removed

    }
