#include<iostream>
#include<string>
#include <vector>
using namespace std;

int main(){

    // char a[1000]={'1','a','c','d'}  not usefull as size has to be specified before
    
    // string s; //Dynamic Array

    // getline(cin,s,'.');  //take input from the user and delimter is '.'

    
    // // to print each character
    // for(char c:s){
    //     cout<<c<<",";
    // }


    // cout<<endl;

    // cout<<s<<endl;


    //---------- Creating vector of strings----------

    // int n=5; // numbers of string taken as input
    // vector<string> sarr;
    // string temp;

    // while(n--){
    //     getline(cin,temp);
    //     sarr.push_back(temp);
    // }
    
    // for(string s:sarr){
    //     cout<<s<<","<<endl;
    // }



    //-----------Searching inside a string -------------------

    string paragraph = "We are learning about STL strings. STL strings class is quite powerfull";

    string word;
    getline(cin,word);

    //find function

    int index=paragraph.find(word);

    if (index!=-1){
    
    cout<<"First occ: "<<index<<endl;
}



    if (index==-1){
        cout<<"String not found"<<endl;
    }

    
    index=paragraph.find(word,index+1);

    if (index!=-1){
        cout<<"Second occur: "<<index<<endl;
    }




    


}
