#include<iostream>
#include <cstring>
#include<vector>
#include<algorithm>
using namespace std;

//Sample Input
/*
3
90 022
82 12
77 14
2 false numerical
*/


//Sample Output
/*
82 12
77 14
90 022
*/


string extractStringAtKey(string str,int key){
	
	//string tokeniser
	
	char *s = strtok((char*)str.c_str()," ");  //converted str to character array
	while(key>1){
		s=strtok(NULL," ");
		key--;
	}
	return (string)s;
}


int convertToInteger(string s){
	int ans=0;
	int p=1;
	for(int i=s.length()-1;i>=0;i--){
		ans+=((s[i]-'0')*p);
		p=p*10;
	}
	return ans;
}


bool lexicoCompare(pair<string,string> s1,pair<string,string> s2){

	string key1,key2;
	key1=s1.second;
	key2=s2.second;
	return key1<key2;
}



bool numericCompare(pair<string,string> s1,pair <string,string> s2){
	string key1,key2;
	key1=s1.second;
	key2=s2.second;

	return convertToInteger(key1)<convertToInteger(key2);
}






int main(){

	// string s="20 30 40 50";
	// cout<<extractStringAtKey(s,2)<<endl;
	
	int n;
	cin>>n;
	cin.get(); // to take input of newline character
	string temp;
	vector <string> v; 
	for(int i=0;i<n;i++){
		getline(cin,temp);
		v.push_back(temp);
	}
	int key;
	string reversal,ordering;
	cin>>key>>reversal>>ordering; 
	

	//1. to extract keys for comparison we will use tokenization

	vector<pair<string,string>>vp;

	for(int i=0;i<n;i++){
		vp.push_back({v[i],extractStringAtKey(v[i],key)});
	}

	//2.Sorting

	if(ordering=="numerical"){
		sort(vp.begin(),vp.end(),numericCompare);
	}
	else{
		sort(vp.begin(),vp.end(),lexicoCompare);
	}


	// 3.for reversal
	if(reversal=="true"){
		reverse(vp.begin(),vp.end());
	}


	// 4. output
	for(int i=0;i<n;i++){
		cout<<vp[i].first<<endl;
	}


	return 0;


}
		
