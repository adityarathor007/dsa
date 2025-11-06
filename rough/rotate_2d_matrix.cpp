#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

    return;
}

int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
//    infile.ignore();
   while(t--){
       //C-1: for vector input: infile >> vec[i]; and the numbers in the input file should be space seperated
       //C-2: if number of elements in the vector is not provided(after infile of t do infile.ignore() to remove the nextLine character from the buffer)
       //string line;
       //getline(infile,line);
       //stringstream ss(line);
       //vector<int>arr;       
       //int num;               
       //while(ss>>num) arr.push_back(num);
       int n;
       infile>>n;
       vector<vector<int>>matrix(n,vector<int>(n));
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            infile>>matrix[i][j];
            // cout<<matrix[i][j]<<" ";
        }
        // cout<<endl;
       }

       rotate(matrix);

       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
       }cout<<endl;      
   }
return 0;
}