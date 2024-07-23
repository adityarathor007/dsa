#include<bits/stdc++.h>
using namespace std;

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;
        vector<int> a(n,0);
        a[0]=1;
        a[1]=1;
        if(n==1 and n==2){
                cout<<a[n-1]<<endl;
        }
        for(int i=2;i<n;i++){
                a[i]=a[i-1]+a[i-2];
        }
        cout<<a[n-1]<<endl;
        

}