#include<iostream>
#include<vector>
using namespace std;

vector<int> findMajorityElementwithn_3(vector<int>&arr){
	int cnt1=0,cnt2=0; 
    int c1=0,c2=0;
	int n=arr.size();
	for(int num:nums){
        if(num==c1) cnt1+=1;
        else if(num==c2) cnt2+=1;
        else if(cnt1==0){
            c1=num;
            cnt1=1;
        }
        else if(cnt2==0){
            c2=num;
            cnt2=1;
        }
        else{
            cnt1-=1;
            cnt2-=1;
        }
    }

	cnt1=0;cnt2=0;
    for(int num:nums){
        if(num==c1) cnt1+=1;
        else if(num==c2) cnt2+=1;
    }

    vector<int>ans;
    int n=nums.size();
    if(cnt1>n/3) ans.push_back(c1);
    if(cnt2>n/3) ans.push_back(c2);
    return ans;
}


int main(){
	vector<int>arr{1,2,3,4,4,4,4};
	vector<int>nums=findMajorityElementwithn_3(arr);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<endl;
	}
	return 0;
}
