#include<iostream>
#include<vector>
using namespace std;

int main(){
    //Demo Vector
    // vector<int> arr={1,2,10,43}

    // Fill Constructor
    // vector<int> arr(10,7);
    
    // // Pop Back
    // arr.pop_back();

    // // Push Back
    // arr.push_back(16);


    // //Print all the element
    // for (int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<endl;
    // }


    // 2d vector
    vector<vector <int> > arr={
        {1,2,3},
        {4,5,6},
        {7,8,9,10},
        {11,12},
    };

    
    arr[0][0]+=10;

    // for accessing each element  //.size() gives the size of vector
    for(int i=0;i<arr.size();i++){
        for (int number: arr[i]){  //2nd option of for using for loop
            cout << number << "," ;
        }
        cout<<endl;
    }




    return 0;
}