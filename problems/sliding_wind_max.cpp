#include<iostream>
#include<vector>
using namespace std;


// remember max shouldnt be kept 0 as negative numbers also exists


vector<int> maxInWindow(vector<int> input, int k)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    int cc = 0;
    int size = 0;
    int max = INT16_MIN;
    while (j < input.size())
    {
        cc = input[j];
        cout<<"current element is:"<<cc<<endl;
        if (cc > max)
        {
            max = cc;
        }
        size++;
        j++;
        if (size == k)
        {
            size = 0;
            ans.push_back(max);
            max = INT16_MIN;
            cc = 0;
            j=j-k+1;
        }
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