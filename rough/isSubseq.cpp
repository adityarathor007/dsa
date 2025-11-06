#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int m=s.size();
        int n=t.size();
        while(i<m and j<n){
            if(s[i]==t[j])i+=1;
            j+=1;
        }
        return i==m;
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
       string s,t;
       infile>>s;
       infile>>t;
    //    cout<<s<<" "<<t<<endl;
       if(isSubsequence(s,t)){
        cout<<"True"<<endl;
       }
       else{
        cout<<"False"<<endl;
       }


                               
   }
return 0;
}