#include<iostream>
#include <vector>
#include <string>
using namespace std;

// Complete this method, don't write main
vector<string> fizzbuzz(int n)
{
    vector <string> arr;
    for (int i=1;i<n+1;i++){

        if (i % 3 == 0 & i % 5 == 0)
        {
            arr.push_back("FizzBuzz");
        }
        else if(i%3==0){
            arr.push_back("Fizz");
        }
        else if(i%5==0){
            arr.push_back("Buzz");
        }
        else{
            arr.push_back(to_string(i));  //to push number as string
        }
        
    }
    return arr;

}


int main(){
    vector<string> arr;
    arr=fizzbuzz(15);


    for (int i = 0; i < arr.size(); i++)
    {
        
        cout << arr[i] << ",";
    }
    cout << endl;
}