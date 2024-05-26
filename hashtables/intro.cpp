#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string,int> menu;

    // Inserting key value pairs inside hashtable O(1) hashtable
    menu["maggi"]=15;
    menu["cold_drink"]=20;
    menu["dosa"]=24;

    //Update works in O(1) time
    menu["dosa"]=(1+0.1)*menu["dosa"];

    // Erase works in O(1) time
    menu.erase("dosa");
    
    
    //Search in O(1) time
    // string item;
    // cin>>item;

    // if(menu.count(item)==0){
    //     cout<<item<<" is not available";
    // }
    // else{
    //     cout<<item<<" is available and the cost is "<< menu[item];
    // }
    // cout<<endl;


    // We can iterate over all key-value pairs that are present

    for(pair<string,int> item: menu){
        cout<<item.first<<"- "<<item.second<<endl;
    }



    return 0;


}