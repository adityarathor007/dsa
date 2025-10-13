#include <bits/stdc++.h>
using namespace std;


int gcd(int a,int b){
        while(a>0 and b>0){
            if(a>b) a=a%b;
            else b=b%a;
        }
        return a!=0?a:b;
    }

string gcdOfStrings(string str1, string str2) {

        // Brute Force method for checking the prefixStrings from start to end and see if it divides both str1 and str2

        // int n=str1.size();
        // int m=str2.size();
        // if(n<m) return gcdOfStrings(str2,str1);

        // string ans="";
        // string temp1="";
        // for(int i=0;i<m;i++){
        //     temp1+=str2[i];
        //     int current_size=i+1;
        //     if(n%current_size!=0) continue;
        //     bool isPossible=true;
        //     for(int j=0;j<n-current_size+1;j+=current_size){
        //         string temp2=str1.substr(j,current_size);
        //         if(temp1!=temp2){
        //             isPossible=false;
        //             break;
        //         }
        //     }

        //     if(m%current_size!=0) continue;
        //     for(int j=0;j<m-current_size+1;j+=current_size){
        //         string temp2=str2.substr(j,current_size);
        //         if(temp1!=temp2){
        //             isPossible=false;
        //             break;
        //         }
        //     }

        //     if(isPossible) ans=temp1;
        // }

        // return ans;


        // Optimized method

        if(str1+str2!=str2+str1) return "";

        int ans_len=gcd(str1.size(),str2.size());

        return str1.substr(0,ans_len);

    }

int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   infile.ignore();
   while(t--){
       string a,b;
       infile>>a>>b;
       cout<<"Output: "<<gcdOfStrings(a,b)<<endl;
   }
return 0;
}
