#include <bits/stdc++.h>
using namespace std;

bool isBalanced(vector<int>freq){
    int first_freq=-1;
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            if(first_freq==-1) first_freq=freq[i];
            else if(freq[i]!=first_freq){

                // cout<<i<<" "<<freq[i]<<endl;
                return false;
            }
        }
    }
    return true;
}


int balancedString(string&s){
    int n=s.size();
    int maxLen=0;
    for(int i=0;i<n;i++){
        vector<int>freq(26,0);
        for(int j=i;j<n;j++){
            // cout<<s.substr(i,j-i+1)<<endl;
            freq[s[j]-'a']+=1;
            if(isBalanced(freq)) maxLen=max(maxLen,j-i+1);
        }
    }
    return maxLen;
}


int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   infile.ignore();
   while(t--){
       //C-1: for vector input: infile >> vec[i]; and the numbers in the input file should be space seperated
       //C-2: if number of elements in the vector is not provided(after infile of t do infile.ignore() to remove the nextLine character from the buffer)
       //string line;
       //getline(infile,line);
       //stringstream ss(line);
       //vector<int>arr;
       //int num;
       //while(ss>>num) arr.push_back(num);

       string a;
       infile>>a;
       cout<<balancedString(a)<<endl;

   }
return 0;
}
