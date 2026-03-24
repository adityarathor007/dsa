int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 1;
        int i=0,start=-1;
        int max_len=1;
        int prev_op=0;

        while(i<n){
            int lv,rv;
            if(!i){
                rv=arr[i+1];
                if(arr[i]>=rv) lv=INT_MIN;
                else if(arr[i]<rv) lv=INT_MAX;
            }
            else if(i==n-1){
                lv=arr[i-1];
                if(arr[i]>=lv) rv=INT_MIN;
                else if(arr[i]<lv) rv=INT_MAX;
            }
            else{
                lv=arr[i-1];
                rv=arr[i+1];
            }

            if((lv<arr[i] and rv<arr[i]) or (lv>arr[i] and rv>arr[i])){ //turbulent condition
                if(start==-1){
                    if(!i) start=i;
                    else start=i-1;
                }
            }
            else{
                if(start!=-1) max_len=max(max_len,i-start+1);
                start=-1;
            }

            i+=1;
        }

        if(start!=-1) max_len=max(max_len,i-start);

        return max_len;

    }
