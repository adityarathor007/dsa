#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;




// this approach takes O(n) time as for each element searching in the unordered set requires O(1) time
vector <int> pairSum(vector <int> arr, int s){
    
    unordered_set <int> set;
    vector<int> result;
    int number;
    for(int i=0;i<arr.size();i++){
        number=s-arr[i];
        if(set.find(number)!=set.end()){
            result.push_back(arr[i]);
            result.push_back(number);
            return result;
        }
        else{
            set.insert(arr[i]);
        }
    }
    return {};

}







int main(){
    vector <int> arr{10,2,4,5,-6,12};
    int s=4;
    
    auto p = pairSum(arr,s);
    
    
    if(p.size()==0){
        cout<<"No such pair"<<endl;
    }
    else{
        cout<<p[0]<<" and "<<p[1]<<endl;
    }

    return 0;
}