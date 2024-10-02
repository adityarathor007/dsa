#include<iostream>
#include<vector>
using namespace std;

void leftRotate(vector<int>&arr,int d){
	int n=arr.size();
	for(int i=0;i<d;i++){
		int start=arr[0];
		for(int i=0;i<n-1;i++){
			arr[i]=arr[i+1];	
		}
		arr[n-1]=start;
	}


}



int main(){

vector<int>arr{1,2,3,4};
int d=3;
leftRotate(arr,d);
int n=arr.size();
for(int i=0;i<n;i++){
	cout<<arr[i]<<",";

}
cout<<endl;
return 0;


}
