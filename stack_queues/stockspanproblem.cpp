#include<iostream>
#include <vector>
#include<stack>
using namespace std;
//the idea is that if p0<p1 and p1<p2 then it is obvious that p0<p2

//using stack O(N)
vector <int> stockSpan(vector <int> v){
    int n=v.size();
    vector<int> ans(n);  //giving size is necessary as when we accessing an element using ([]) that hasn't been allocated, it will lead to undefined behavior, which can cause a segmentation fault.
    ans[0]=1;
   
    stack <int> s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() and v[s.top()]<=v[i]){
            s.pop();
        }
        if(!s.empty()){
            ans[i]=i-s.top();
        }
        else{
            ans[i]=i+1;
        }
        s.push(i);
    }
    
    
    return ans;
}




//brute force O(N2)
// vector<int> stockSpan(vector<int> v) {
// //Write your code here. Do not modify the function or parameters.
//     vector<int> ans;
//     for(int i=0;i<v.size();i++){
//         int count=0;
//         for(int j=i;j>=0;j--){
//             if(v[i]>=v[j]){
//                 count++;
//             }
//             else{
//                 break;
//             }
        
//         }
//         ans.push_back(count);
    
//     }
//     return ans;
    
// }   

int main(){
    vector<int>input={100, 80, 60, 70, 60, 75, 85};
    auto ans=stockSpan(input);
    for(int x:ans){
        cout<<x<<",";
    }
    cout<<endl;
}