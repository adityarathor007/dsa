#include<iostream>
#include<vector>
using namespace std;


// remember max shouldnt be kept 0 as negative numbers also exists


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            // Remove elements outside the window
            if(!dq.empty() and dq.front()<=i-k){
                dq.pop_front();
            }
            // Maintain decreasing order in deque
            while(!dq.empty() and nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            // add maximum for the current window
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
}

int main(){
    vector<int> input = {-1, -1, -2,-1,-3};
    int k=3;
    vector <int> p=maxInWindow(input,k);
    // //Print all the element
    for (int i=0;i<p.size();i++){
        cout<<p[i]<<',';
    }
    cout<<endl;
}
