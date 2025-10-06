// input: beginWord endWord and wordList

#include <bits/stdc++.h>
using namespace std;



int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>dict;
        for(auto word:wordList) dict.insert(word);

        int word_len=beginWord.size();

        while(!q.empty()){
            auto curr_pair=q.front();
            q.pop();
            string curr_word=curr_pair.first;
            int curr_level=curr_pair.second;

            if(curr_word==endWord) return curr_level;

            for(int i=0;i<word_len;i++){
                char char_to_replace=curr_word[i];
                for(char letter='a';letter<='z';letter++){
                    if(letter!=char_to_replace){
                        curr_word[i]=letter;
                        if(dict.find(curr_word)!=dict.end()){
                            q.push({curr_word,curr_level+1});
                            dict.erase(curr_word);
                        }
                    }
                }
                curr_word[i]=char_to_replace;
            }

        }

        return 0;


}


int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   infile.ignore();
   while(t--){
       // for vector input: infile >> vec[i]; and the numbers in the input file should be space seperated
        string beginWord,endWord,line;
        infile>>beginWord>>endWord;

        infile.ignore();

        vector<string>wordList;

        if (getline(infile, line)) {
            stringstream ss(line);
            string word;
            while (ss >> word) {
                wordList.push_back(word);
            }
        }

        cout<<beginWord<<" "<<endWord<<endl;
        for(auto word:wordList)cout<<word<<", ";
        cout<<endl;

        cout<<ladderLength(beginWord,endWord,wordList)<<endl;



   }
return 0;
}


