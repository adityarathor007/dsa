#include <iostream>
#include<vector>
using namespace std;

void sortArrayof012(vector<int>&arr){
    int c0=0;
    int c1=0;
    int c2=0;
    for(int x:arr){
        if(x==0) c0+=1;
        else if(x==1) c1+=1;
        else if(x==2) c2+=1;
    }

    // arr.clear();
    for(int i=0;i<c1;i++){
        arr[i]=0;
    }
    for(int i=c1;i<c1+c2;i++){
        arr[i]=1;
    }
    for(int i=c1+c2;i<c0+c1+c2;i++){
        arr[i]=2;
    }
    

return ;

}


int main() {

    vector<int>arr{2,0,2,1,1,0};
    sortArrayof012(arr);
    for(auto x:arr){
        cout<<x<<",";
    }
    cout<<endl;

    return 0;
}