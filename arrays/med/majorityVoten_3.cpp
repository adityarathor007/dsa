#include<iostream>
#include<vector>
using namespace std;

vector<int> findMajorityElementwithn_3(vector<int>&arr){
	int e1=0;
	int e2=0;
	int cnt1=0;
	int cnt2=0;
	int n=arr.size();
	for(int i=0;i<n;i++){
		if(e1==arr[i]){
			cnt1+=1;	
		}	
		else if(cnt1==0){
			e1=arr[i];
			cnt1+=1;	
		}
		else if(e2==arr[i]){
			cnt2+=1;
		}
		else if(cnt2==0){
			e2=arr[i];
			cnt2+=1;
		}
		else{
			cnt1=0;
			cnt2=0;
		}
	}

	int freq1=0;
	int freq2=0;
	for(int i=0;i<n;i++){
		if(arr[i]==e1) freq1+=1;
		else if(arr[i]==e2) freq2+=1;
	}
	int majority=n/3+1;
	vector<int>ans;

	if(freq1>=majority) ans.push_back(e1);
	if(freq2>=majority) ans.push_back(e2);
	if(ans.empty()) ans.push_back(-1);

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
