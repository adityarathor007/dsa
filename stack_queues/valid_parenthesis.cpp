#include <bits/stdc++.h>
using namespace std;

bool validParenthesis(string s){
    stack<char>st;

    for(char ch:s){
        if(ch=='(' or ch=='{' or ch=='[') st.push(ch);
        else if(ch==')'){
            if(st.empty() or st.top()!='(') return false;
            st.pop();
        }
        else if(ch=='}'){
            if(st.empty() or st.top()!='{') return false;
            st.pop();
        }
        else{
            if(st.empty() or st.top()!='[') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   while(t--){
       //C-1: for vector input: infile >> vec[i]; and the numbers in the input file should be space seperated
       //C-2: if number of elements in the vector is not provided(after infile of t do infile.ignore() to remove the nextLine character from the buffer)
       string input;
       infile>>input;
       if(validParenthesis(input)) cout<<"Yes it is valid parenthesis"<<endl;
       else cout<<"Not valid parenthesis"<<endl;

   }
return 0;
}
