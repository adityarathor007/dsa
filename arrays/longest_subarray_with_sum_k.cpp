int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> prefixMap;
        int prefixSum = 0;
        int max_len = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            if (prefixSum == k)
                max_len = i + 1;

            if (prefixMap.count(prefixSum - k))
                max_len = max(max_len, i - prefixMap[prefixSum - k]);

            if (!prefixMap.count(prefixSum))
                prefixMap[prefixSum] = i;   // store earliest index only
        }

        return max_len;
    }
