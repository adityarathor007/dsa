void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1;
        int r=m+n-1;

        while(j!=-1){
            // cout<<nums2[j]<<" "<<i<<" "<<r<<endl;
            if(i==-1){
                nums1[r]=nums2[j];
                j-=1;
            }

            else{
                if(nums1[i]<nums2[j]){
                    nums1[r]=nums2[j];
                    j-=1;
                }
                else{
                    nums1[r]=nums1[i];
                    i-=1;
                }
            }
            r-=1;
        }
        return;
    }
