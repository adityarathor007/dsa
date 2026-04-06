// First thing: Rain water is trapped if there is a taller building to the left and to the right then it will be stored based on the min of both - current height
        int n=height.size();
        int left=0,right=n-1;
        int leftMax=0,rightMax=0;
        int total=0;
        while(left<=right){
            if(height[left]<height[right]){  //means the current height is controlled by leftMax (for sure so we compute for left) because the rightBoundary is taller as rightMax=max(rightMax,rh);
                leftMax=max(leftMax,height[left]); //deciding the left boundary
                total+=(leftMax-height[left]);
                left+=1; //moving because for water calculation is done
            }
            else{
                rightMax=max(rightMax,height[right]);
                total+=(rightMax-height[right]);
                right-=1;
            }
        }
        return total;
    }
