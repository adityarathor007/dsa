#include <bits/stdc++.h>
using namespace std;


void dfs(string currWord,vector<string>&seq,string &beginWord,unordered_map<string,int>&mpp,vector<vector<string>>&ans){

        if(currWord==beginWord){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return ;
        }

        int cl=mpp[currWord];

        for(int i=0;i<currWord.size();i++){
            char original=currWord[i];
            for(char ch='a';ch<='z';ch++){
                currWord[i]=ch;
                if(mpp.find(currWord)!=mpp.end() and mpp[currWord]+1==cl){
                    seq.push_back(currWord);
                    dfs(currWord,seq,beginWord,mpp,ans);
                    seq.pop_back();
                }
            }
            currWord[i]=original;
        }

        return;

    }


vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string,int>mpp;
        vector<vector<string>>ans;



         // first compute the possible level for the path to reach the endWord
        queue<string>q;
        q.push(beginWord);

        mpp[beginWord]=0;
        int wl=beginWord.size();

        unordered_set<string>wordSet(wordList.begin(),wordList.end());

        // for(auto it=wordSet.begin();it!=wordSet.end();it++){
        //     cout<<*it<<endl;
        // }

        if(wordSet.find(beginWord)!=wordSet.end()) wordSet.erase(beginWord);


        while(!q.empty()){
            string cw=q.front();
            // cout<<cw<<endl;
            q.pop();

            if(cw==endWord) break;
            int cl=mpp[cw];
            for(int i=0;i<wl;i++){
                char original=cw[i];
                for(char ch='a';ch<='z';ch++){
                    cw[i]=ch;
                    // cout<<cw<<endl;
                    if(wordSet.find(cw)!=wordSet.end() and ch!=original){
                        mpp[cw]=cl+1;
                        q.push(cw);
                        wordSet.erase(cw);
                    }
                }
                cw[i]=original;
            }

        }

        // for(auto pair:mpp){
        //     cout<<pair.first<<"-"<<pair.second<<endl;
        // }

        //then apply dfs from endWord to beginWord
        vector<string>seq;
        seq.push_back(endWord);
        dfs(endWord,seq,beginWord,mpp,ans);
        return ans;





        // The below code give TLE error because we are storing paths inside queue
        //  vector<vector<string>>ans;
        //  queue<vector<string>>q;
        //  vector<string>buff;
        //  unordered_set<string>wordSet(wordList.begin(),wordList.end());
        //  buff.push_back(beginWord);
        //  q.push(buff);

        //  int wordLen=beginWord.size();


        //  while(!q.empty()){
        //     int size=q.size();
        //     for(int i=0;i<size;i++){ //iterating at the same level as to keep track of the level

        //         buff=q.front();
        //         q.pop();
        //         string cw=buff.back();

        //         //removing the last word from the set and not removing when it first occurs (explained below)
        //         wordSet.erase(cw);


        //         if(cw==endWord){
        //             ans.push_back(buff);
        //             if(i==size-1) return ans;
        //             continue;
        //         }

        //         for(int j=0;j<wordLen;j++){
        //             char original=cw[j];
        //             for(char ch='a';ch<='z';ch++){
        //                 cw[j]=ch;
        //                 if(wordSet.find(cw)!=wordSet.end()){
        //                     buff.push_back(cw);
        //                     q.push(buff); //not removing the word from the set as that cw can occur from other seq at the same level
        //                     buff.pop_back();
        //                 }
        //             }
        //             cw[j]=original;
        //         }


        //     }

        //  }

        //  return ans;


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

        // cout<<beginWord<<" "<<endWord<<endl;
        // for(auto word:wordList)cout<<word<<", ";
        // cout<<endl;

        auto ans=findLadders(beginWord,endWord,wordList);
        cout<<"Output: "<<endl;
        for(auto ladder:ans){
            for(string word:ladder){
                cout<<word<<", ";
            }
            cout<<endl;
        }



   }
return 0;
}
