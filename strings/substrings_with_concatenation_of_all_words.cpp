class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty()) return result;

        int word_len = words[0].size();
        int word_count = words.size();
        int total_len = word_len * word_count;
        int n = s.size();

        if (n < total_len) return result;

        unordered_map<string, int> word_freq;
        for (auto &w : words) word_freq[w]++;

        // Check each offset 0..L-1
        for (int offset = 0; offset < word_len; offset++) {

            unordered_map<string, int> window_count;
            int left = offset; // sliding window start
            int matched_words = 0;

            // Move in steps of word_len
            for (int right = offset; right + word_len <= n; right += word_len) {

                string w = s.substr(right, word_len);

                // If w is a valid word
                if (word_freq.count(w)) {
                    window_count[w]++;
                    matched_words++;

                    // If too many occurrences of w, shrink window
                    while (window_count[w] > word_freq[w]) {
                        string left_word = s.substr(left, word_len);
                        window_count[left_word]--;
                        matched_words--;
                        left += word_len;
                    }

                    // If full valid window found
                    if (matched_words == word_count) {
                        result.push_back(left);

                        // shrink by removing the leftmost word
                        string left_word = s.substr(left, word_len);
                        window_count[left_word]--;
                        matched_words--;
                        left += word_len;
                    }

                } else {
                    // Reset if invalid word encountered
                    window_count.clear();
                    matched_words = 0;
                    left = right + word_len;
                }
            }
        }

        return result;
    }
};
