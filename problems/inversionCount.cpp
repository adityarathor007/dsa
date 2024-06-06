#include <iostream>
#include <vector>
using namespace std;


int mergeCount(vector <int> &array,int s,int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    int cnt=0;
    vector<int> temp; 
    while (i <= m and j <= e)
    {
        
        if(array[i]>array[j]){
            cnt += (m - i + 1);
            temp.push_back(array[j]);
            j++;
        }
        else
        {
           
            temp.push_back(array[i]);
            i++;
        }
    }

    while (i <= m){
        temp.push_back(array[i]);
        i++;
    }

    while (j <= e)
    {
        temp.push_back(array[j]);
        j++;
    }

    // to make a part of array sorted
    int k=0;
    for(int i=s;i<=e;i++){
        array[i]=temp[k++];
        
    }


    return cnt;

}






int inversionCount(vector<int> &array,int s,int e){
    //base case
    if(s>=e){
        return 0;
    }
    //recursive case
   
    int m=(s+e)/2;
    int Cl=inversionCount(array,s,m);
    int Cr=inversionCount(array,m+1,e);
    int Ci=mergeCount(array,s,e);
    cout<<"Cl value is "<<Cl<<endl;
    cout<<"Cr value is "<<Cr<<endl;
    cout<<"Ci value is "<<Ci<<endl;
    return Cl + Cr + Ci;



}






int main(){
    vector<int> a={0,5,2,3,1};
    int s=0;
    int e=a.size()-1;
    cout<<inversionCount(a,s,e)<<endl;
    for (int x : a)
    {
        cout << x << ", ";
    }
    cout<<endl;
}