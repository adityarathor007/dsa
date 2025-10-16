// two strings are closer if you can attain one from the other using the following operation applied to a string any number of times
// Operation1: Swap 2 exisiting chars
// Operations2: Transform every occurence of one exisiting characters into another exisiting characters and do the same for the other character


bool closeStrings(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();

        if(n!=m) return false;



        vector<int> counts1(26, 0), counts2(26, 0);
        for_each(word1.begin(), word1.end(), [&](auto& c) {
            counts1[c - 'a'] ++;
        });
        for_each(word2.begin(), word2.end(), [&](auto& c) {
            counts2[c - 'a'] ++;
        });

        //checking of unique chars
        for (size_t i = 0; i < counts1.size(); i ++) {
            if((counts1[i] == 0 && counts2[i] != 0) || (counts1[i] == 0 && counts2[i] != 0)) {
                return false;
            }
        }

        unordered_map<int, int> umap1, umap2; //to store the unique possible counts
        for_each(counts1.begin(), counts1.end(), [&](auto& i){
            umap1[i] ++;
        });
        for_each(counts2.begin(), counts2.end(), [&](auto& i){
            umap2[i] ++;
        });

        for (auto& [k, v] : umap1) {
            if (!umap2.contains(k)) {
                return false;
            }
            if (umap2[k] != v) {
                return false;
            }
        }
        return true;
    }
