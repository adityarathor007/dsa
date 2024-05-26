#include <iostream>
#include <vector>
using namespace std;

int highest_mountain(vector<int> arr){
    int n=arr.size();

    int largest=0;

    for(int i=1;i<n-2;){  // the first and last element cant be the peak
        if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){  // to say if a particular point is peak or not
            int cnt=1;
            int j=i;
            
            // count backwards
            while(j>=1 and arr[j]>arr[j-1]){
                j--;
                cnt++;

            }


            // and count forward

            while(i<=n-2 and arr[i]>arr[i+1]){
                cnt++;
                i++;
            }

            if (cnt > largest)
            {
                largest = cnt;
            }
        }


        else{
            i++;
        }   
       
        


    }

    return largest;
}


int main(){
    vector <int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    


    cout<<highest_mountain(arr)<<endl;


    return 0;
}