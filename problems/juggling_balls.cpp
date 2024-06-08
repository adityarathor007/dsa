#include <iostream>
using namespace std;

vector<int> sortBalls(vector<int> balls){
    //sort the balls in place in a single pass (O(N) time, O(1) space)
    int n=balls.size();
    int low=0;
    int mid=0;
    int high=n-1;
    
    
    while(mid<=high){
        if(balls[mid]==0){
            swap(balls[low],balls[mid]);
            mid++;
            low++;
        }
        else if(balls[mid]==1){
            mid++;
        }
        else if(balls[mid]==2){
            swap(balls[mid],balls[high]);
            high--;
        }
    }
 
    
        
    
    return balls;
}




int main(){
    vector <int> input={ 0, 1, 1, 2, 2, 1, 1 };
    input=sortBalls(input);
    
    for(int x:input){
        cout<<x<<',';
    }
    cout<<endl;
    
}