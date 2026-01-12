void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        //CASE 1:  when extra space is given at the back of nums1
        // int i=m-1,j=n-1;
        // int r=m+n-1;

        // while(j!=-1){
        //     // cout<<nums2[j]<<" "<<i<<" "<<r<<endl;
        //     if(i==-1){
        //         nums1[r]=nums2[j];
        //         j-=1;
        //     }

        //     else{
        //         if(nums1[i]<nums2[j]){
        //             nums1[r]=nums2[j];
        //             j-=1;
        //         }
        //         else{
        //             nums1[r]=nums1[i];
        //             i-=1;
        //         }
        //     }
        //     r-=1;
        // }
        // return;

        //CASE 2: if no extra space is given at the back
        // intution the larger element should come on the right side and smaller element on the left
        //TO make this happen we need to ensure that the largest element of the nums1 should be less then equal to smaller element of the nums2
        int i=m-1;
        int j=0;
        while(i>=0 and j<n){
            if(nums1[i]>nums2[j]) swap(nums1[i],nums2[j]);
            else break;
            i-=1;
            j+=1;
        }

        // we have placed them in the correct position but may not be sorted 
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        return ;
    }
