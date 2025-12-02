#include <bits/stdc++.h>
using namespace std;


// water=(distance between lines)×min(their heights)
int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int maxArea=0;
        while(i<j){
            int ch=min(height[i],height[j]);
            maxArea=max(maxArea,ch*(j-i));
            if(height[i]<height[j]) i+=1;
            else j-=1;
        }

        return maxArea;
    }


int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   infile.ignore();
   while(t--){
       //C-1: for vector input: infile >> vec[i]; and the numbers in the input file should be space seperated
       //C-2: if number of elements in the vector is not provided(after infile of t do infile.ignore() to remove the nextLine character from the buffer)
       string line;
       getline(infile,line);
       stringstream ss(line);
       vector<int>arr;
       int num;
       while(ss>>num) arr.push_back(num);
       cout<<maxArea(arr)<<endl;

   }
return 0;
}
