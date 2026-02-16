// arr = [1, 2, 1, 1, 3]
// You are given an array    arr, you need to find any three elements in it such that arr[i] < arr[j] < arr[k] and i < j < k.



class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        
        // brute force(O(n^3))
        int n=arr.size();
        vector<int>ans;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(arr[i]<arr[j]){
        //             for(int k=j+1;k<n;k++){
        //                 if(arr[j]<arr[k]){
        //                     ans.push_back(arr[i]);
        //                     ans.push_back(arr[j]);
        //                     ans.push_back(arr[k]);
        //                 }
        //             }
        //         }
                
        //     }
            
        // }
        
        
        
        vector<int>smaller(n,-1); //storing the most minimum of the elements on the left of that index
        vector<int>greater(n,-1); //storing the index of the maximum element on the right of that index
        int min_e=arr[0];
        int index=0;
        for(int i=1;i<n;i++){
            if(arr[i]>min_e){
                smaller[i]=index;
            }
            else{
                min_e=arr[i];
                index=i;
            }
        }
        
        int max_e=arr[n-1];
        index=n-1;
        for(int i=n-1;i>=0;i--){
            if(arr[i]<max_e){
                greater[i]=index;
            }
            else{
                max_e=arr[i];
                index=i;
            }
        }
        
 
        
        
        for(int i=1;i<n-1;i++){
            if(smaller[i]!=-1 and greater[i]!=-1){
                
                ans.push_back(arr[smaller[i]]);
                ans.push_back(arr[i]);
                ans.push_back(arr[greater[i]]);
                break;
            }
        }
        
        
        
        
        
        return ans;
        
        
        
    }
};  