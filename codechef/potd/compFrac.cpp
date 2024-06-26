#include<iostream>
#include <string>
#include <sstream>
using namespace std;


string compareFrac(string str)
{

    // Code here
    stringstream ss(str);
    string f1,f2;
    string n1,d1,n2,d2;
    
    getline(ss, f1, ',');
    ss >> ws;
    getline(ss, f2);

    size_t pos = f1.find('/');

    n1 = f1.substr(0, pos);
    d1 = f1.substr(pos + 1);

    pos = f2.find('/');
    n2 = f2.substr(0, pos);
    d2 = f2.substr(pos + 1);

    int num1=stoi(n1);
    int num2=stoi(n2);
    int den1=stoi(d1);
    int den2=stoi(d2);
    int ans=num1*den2-num2*den1;
    
    if (ans>0)
    {
        return f1;
    }
    else if (ans<0)
    {
        return f2;
    }
    else
    {
        return "equal";
    }
}

int main(){
    cout<<compareFrac("5/6, 11/45")<<endl;
}