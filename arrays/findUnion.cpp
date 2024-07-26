 #include<iostream>
 #include<vector>
 using namespace std;
 
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i=0;
        int j=0;
        vector<int>ans;
        while(i<n and j<m){
        
            if(arr1[i]<=arr2[j]){
               if(ans.size()==0|| ans.back()!=arr1[i]) {
                   
                ans.push_back(arr1[i]);
               }
                i++;
            }
            
            else if(arr1[i]>arr2[j]){
                if(ans.size()==0|| ans.back()!=arr2[j]){
                    ans.push_back(arr2[j]);
                }
                
                j++;
            }
                
            
           
            
        }
        while(i<n){
            if(ans.size()==0|| ans.back()!=arr1[i]){
                 ans.push_back(arr1[i]);
            }
            
            i++;
        }
        while(j<m){
            if(ans.size()==0|| ans.back()!=arr2[j]){
                 ans.push_back(arr2[j]);
            }
            
            j++;
        }
         return ans;
    }
int main(){
    int n=9;
    int m=3;
    int arr1[]={-8,-3,-3,-2,0,1,2,2,6};
    int arr2[]={-9,-9,0};
    auto ans=findUnion(arr1,arr2,n,m);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
    cout<<endl;

}