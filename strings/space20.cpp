#include<iostream>
#include<string>
#include<vector>
using namespace std;



vector<int> findspaces_post(string in){
    //store the occurrences in the result vector
    vector<int> result = {};
    
    int i=0;
    int index;
    while(i<=in.length()){
        index=in.find(' ',i);
        if(index==-1){
            break;
        }
        i=index+1;
        result.push_back(index);
    }
    return result;


}


bool SpaceExists(int a, vector<int> post){
	for(int x:post){
	if(a==x){
	return true;
}
}
return false;
}



string insert_per_20(string str){
	
	vector<int>post=findspaces_post(str);
	int n_spaces=post.size();
	cout<<"number of spaces "<<n_spaces<<endl;
	int act_size=str.size()+(n_spaces*2);

	string rep(act_size, '\0');
	int j=act_size-1;
	
	cout<<"old size "<<str.size()<<endl;
	for(int i=str.size()-1;i>=0;i--){

		if (!SpaceExists(i,post)){
		rep[j]=str[i];
		cout<<"non space char: "<<str[i]<<endl;
		cout<<"new position: "<<j<<endl;
		j--;
		}
		else{
		cout<<"the value of index where 0 starts "<<j-1<<endl;
		rep[j]='0';
		rep[j-1]='2';
		rep[j-2]='%';
		j-=3;
		}	
	

	}
	cout<<"the output is "<<endl;
	cout<<rep<<endl;

	return rep;
}



int main(){
	string str={"Hi this is a CPP program"};
	string ans=insert_per_20(str);
	cout<<ans<<endl;
	return 0;


}
