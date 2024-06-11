#include <bits/stdc++.h>
using namespace std;

long long int Mod = 1e9 + 7;

long long int powerModulo(int a, int b)
{

    if (b == 0)
    {
        return 1;
    }
    long long int half = powerModulo(a, b / 2);
    long long int result = (half * half) % Mod;
    // if (b % 2 != 0)
    if(b&1) //another method to check if a number is odd or not
    {
        result = (result * (a % Mod)) % Mod; 
    }
    return result;
}

int main(){
    int a;
    int b;
    cin>>a;
    cin>>b;
    cout<<powerModulo(a,b)<<endl;
}