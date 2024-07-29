#include<iostream>
#include<math.h>
using namespace std;
// swap 2 num without using a temp variable

int main(){
    // int a,b;
    // cin>>a>>b;
    // int a1=0,b1=0;
    // for(int i=0;i<32;i++){
    //     int bit1=a&1;
    //     int bit2=b&1;
    //     a=a>>1;
    //     b=b>>1;
    //     if(bit1^bit2){
    //         a1+=pow(2,i)*(!bit1);
    //         b1+=pow(2,i)*(!bit2);
    //     }
    //     else{
    //         a1+=pow(2,i)*(bit1);
    //         b1+=pow(2,i)*(bit2);

    //     }

    // }
    // cout<<a1<<" - "<<b1<<endl;

    // easier method
    int a,b;
    cin>>a>>b;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<" - "<<b<<endl;

}
