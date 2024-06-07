#include <bits/stdc++.h>
#include <optional>
#include <vector>
using namespace std;

int badness(vector<pair<string, int>> teams)
{
   vector<string> l;
   for(auto pair:teams){
    if(l[pair.second].has_value()){
        l[pair.second]=pair.first;
    }
   }
return 1;

}


int main(){
    vector<pair<string, int>> input = {{"A", 1}, {"B", 2}, {"C", 2}, {"D", 1}, {"E", 5}, {"F", 7},{"G",8}};
    cout<<badness(input)<<endl;

}