// First thing: Rain water is trapped if there is a taller building to the left and to the right then it will be stored based on the min of both - current height
        int n=height.size();
        int left=0,right=n-1;
        int leftMax=0,rightMax=0;
        int total=0;
        while(left<=right){
            if(height[left]<height[right]){  //means the current height is controlled by leftMax because the rightBoundary is taller as height[right]<=rightMax
                if(height[left]>leftMax) leftMax=height[left]; //no leftBoundary
                else total+=(leftMax-height[left]);
                left+=1;
            }
            else{
                if(height[right]>rightMax) rightMax=height[right]; //no rightBoundary so updating it
                else total+=(rightMax-height[right]);
                right-=1;
            }
        }
        return total;
    }
