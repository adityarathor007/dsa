 int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int l=0,r=n-1;
        int mountainIndex=-1;
        while(l<=r){
            int mid=(l+r)/2;
            int prev=mid!=0?mountainArr.get(mid-1):INT_MIN;
            int next=(mid!=n-1)?mountainArr.get(mid+1):INT_MIN;
            int curr=mountainArr.get(mid);
            if(curr>prev and curr>next){
                if(target==curr) return mid;
                mountainIndex=mid;
                break;
            }
            else if(curr<prev) r=mid-1;
            else l=mid+1;
        }

        //the left side which is increasing arr
        l=0,r=mountainIndex-1;
        while(l<=r){
            int mid=(l+r)/2;
            int curr=mountainArr.get(mid);
            if(curr==target) return mid;
            else if(curr>target) r=mid-1;
            else l=mid+1;
        }

        // now the right side which is decreasing arr
        l=mountainIndex+1,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            int curr=mountainArr.get(mid);
            cout<<curr<<endl;
            if(curr==target) return mid;
            else if(curr>target) l=mid+1;
            else r=mid-1;
        }

        return -1;
    }
