#include<iostream>
#include<sstream>
#include<vector>
#include<cstring>
using namespace std;





// !-------------using the already defined strtok-----------------!
// int main(){
// 	char input[1000];
// 	cin.getline(input,1000);

// 	char *token=strtok(input," ");

// 	while(token !=NULL){
	
// 	cout<<token<<endl;
// 	token=strtok(NULL," "); // internally maintains the state of the string using a static varible, passed in the last fn call	

// }
// return 0;

// }

//using self defined function
char *mystrtok(char *str, char delim){

	static char *input=NULL;  // static varible and value doesnt change between function calls

	if(str!=NULL){
		 input=str;
	}

	if(input==NULL){
		return NULL;
	}

	char *token=new char(strlen(input)+1);
	// cout<<token<<endl;
	int i=0;

	for(;input[i]!='\0';i++){
		if(input[i]!=delim){
			token[i]=input[i];
		}
		else{
			token[i]='\0';	
			input=input+i+1;
			return token;
		}
	}

	//out of loop(when delimiter does not occur and end of string comes then we come outside)
	token[i]='\0';

	input=NULL;
	return token;


}


int main(){

	char s[1000];
	cin.getline(s,1000);

	char *token=mystrtok(s,' ');

	while(token!=NULL){
		cout<<token<<endl;
		token=mystrtok(NULL,' ');
	}

	return 0;
}
