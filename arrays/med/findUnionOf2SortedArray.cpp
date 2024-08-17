#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;


// IMP is handling duplicates that dont get added

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int>ans;
        int i=0,j=0;
        int prev=-1;
        while(i<n and j<m){
            if(arr1[i]<arr2[j]){
               
                if(prev!=arr1[i]){
                    ans.push_back(arr1[i]);  
                    prev=arr1[i];
                
                }
                 
                
                i++;
            }
            else if(arr1[i]>arr2[j]){
                if(prev!=arr2[j]){
                    ans.push_back(arr2[j]);
                    prev=arr2[j];
                }
                
                
                j++;
            }
            else{
                
                if(prev!=arr1[i]){
                    ans.push_back(arr1[i]);
                    prev=arr1[i];
                }
                
                i++;
                j++;
            }
        }
        while(i<n){
            if(prev!=arr1[i]){
                ans.push_back(arr1[i]);
                prev=arr1[i];
            }
            
            i++;
        }
        while(j<m){
            if(prev!=arr2[j]){
                ans.push_back(arr2[j]);
                prev=arr2[j];
            }
            j++;
        }
        
        return ans;
    }