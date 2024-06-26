#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void permuate(vector<string> &output,string &s,int l,int r){

    //base case 
    if(l==r){
        // auto it=find(output.begin(),output.end(),s);  // method to check if an element is found in vector or not
        // if(it==output.end()){
        //     output.push_back(s);
        // }
        output.push_back(s);
        
        return ;
    }

    //recursive case 
    for(int i=l;i<=r;i++){
        //swapping
        swap(s[l],s[i]);

        //moving to the next index
        permuate(output,s,l+1,r);

        //backtracking
        swap(s[l],s[i]);


    }


}

vector<string> findSortedPermutations(string s)
{
    // Your code goes here. Do not change the function or parameters. You can use helper functions if needed.
    vector<string> output;
    int l=0;
    int r=s.length()-1;
    permuate(output,s,l,r);
    
    //either pushing in vector then only inserting elments which are not already there to prevent repetation or using a set and inserting elements in it

    set <string> st;  
    for (int i = 0; i < output.size(); i++)
    {
        st.insert(output[i]);
    }

    output.clear();

    for (auto x : st)
    {
        output.push_back(x);
    }
    return output;
    
}


int main(){
    string s="aaa";
    
    auto ans=findSortedPermutations(s);
    for(auto x:ans){
        cout<<x<<endl;
    }

}