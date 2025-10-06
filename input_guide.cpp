#include <bits/stdc++.h>
using namespace std;



//Case 1: just  involving >>operator
// int main() {
//    ifstream infile("input.txt");
//    int t;
//    infile >> t;
//    while(t--){

//         int n;
//         infile>>n;
//         vector<int>nums(n);
//         for(int i=0;i<n;i++) infile>>nums[i];



//    }
// return 0;
// }


//Case 2: if involves both >>operator and getline
int main(){
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
