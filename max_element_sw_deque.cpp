#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> max_in_Subarrayk(vector<int> a,int k){

deque <int> q(k);
int n=a.size();
vector<int> ans;

for(int i=0;i<k;i++){
	while(!q.empty() and a[i]>a[q.front()]){
		q.pop_back();
	} 
	q.push_back(i);

}
for(int i=k;i<n;i++){
	ans.push_back(a[q.front()]);

	while(!q.empty() and q.front()<=(i-k)){
		q.pop_front();
	}
	while(!q.empty() and a[i]>a[q.front()]){
	
		q.pop_back();

}

	q.push_back(i); 


}
	ans.push_back(a[q.front()]); // to cpnsider the last element
	return ans;

}



int main(){

vector<int> input={1,2,3,5,4,2,7,8,9};
int k=3;
auto ans=max_in_Subarrayk(input,k);
for(int x:ans){
	cout<<x<<",";
}
cout<<endl;

return 0;
}


