#include<iostream>
using namespace std;

int setBit(int n) {
        // Write Your Code here
        int f_unset_bit;
        int t=n;
        for(int i=0;i<32;i++){

            if((t&1)==0){
                f_unset_bit=i;
                break;
            }
            t=t>>1;

        }

        int mask=1<<f_unset_bit;
        return (n|mask);
    }

int main(){
    cout<<setBit(15)<<endl;
}

#include <bits/stdc++.h>
using namespace std;

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

   }
return 0;
}
