#include <iostream>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;


vector<vector <int> > tripletSum(vector <int> arr,int s){
    sort(arr.begin(), arr.end()); //here we sorted array as in this approach  O(NlogN) is not the bottleneck as N^2 is present
    // wheras in the pair problem there was O(N) in two pair which is the problem as O(NlogN) is the bottleneck
    vector<vector<int>> result;

        // Pick every a[i],pair sum for remaining part using two pointer approach
        for (int i = 0; i < arr.size() - 3; i++){
        int j=i+1;
        int k=arr.size()-1;

        
        while(j<k){
            int current_sum=arr[i];
            current_sum+=arr[j];
            current_sum+=arr[k];

            if(current_sum==s){
                result.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
            }
            else if(current_sum<s){
                j++;
            }
            else{
                k--;
            }
        }
    }
    return result;
}


// vector<vector <int> > myappro_usingpairsum(vector<int> arr, int s){

//     set<int> a1;
//     set<int> a2;
//     vector <vector <int>> final;
    
//     int n1,n2;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         n1=s-arr[i];
//         cout<<"n1 is "<<n1<<endl;
//         for(int j=i+1;j<arr.size();j++){
//             n2=n1-arr[j];
//             cout<<n2<<endl;
//             a1.insert(arr[i]);
//             if(a1.find(arr[i])!=a1.end() && a2.find(n2)!=a2.end()){
                
//                 vector<int> r1;
//                 r1.push_back(arr[j]);
//                 r1.push_back(n2);
//                 r1.push_back(arr[i]);
//                 final.push_back(r1);
//             }
//             else{
//                 a2.insert(arr[j]);
//             }

//         }
            
//     }
//     return final;
// };

int main()
{
    vector<int> arr{1,2,3,4,5,6,7,8,9,15};
    int s = 18;

    auto result = tripletSum(arr, s);

    for(auto v:result){
        for(auto num: v){
            cout<<num<<", ";
        }
        cout<<endl;
        
    }
   

    return 0;
}
