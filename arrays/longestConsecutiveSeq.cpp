 #include<iostream>
 #include<vector>
 #include<unordered_set>
 using namespace std;
 
 int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int max_c=1;
        // int c=1;
        // int n=nums.size();
        // for(int i=0;i<n-1;i++){
        //     if(nums[i+1]-nums[i]==1){
        //         c+=1;
        //     }
        //     else{
        //         max_c=max(max_c,c);
        //         c=1;
        //     }
        // }
        // max_c=max(max_c,c);
        // return max_c;
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int max_c=1;
        int c=1;

        for(auto it=s.begin();it!=s.end();it++){
            int ele=(*it)-1;
            
            while(s.find(ele)!=s.end()){
                c+=1;
                ele=(*s.find(ele))-1;
            }
            max_c=max(c,max_c);
            c=1;


        }
        return max_c;
    }

    int main(){
        vector<int>nums{100,4,200,1,3,2};
        cout<<longestConsecutive(nums)<<endl;
    }