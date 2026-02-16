
bool canChange(string start, string target) {
    int n=start.size();
    int waitL=0,waitR=0;
    for(int i=0;i<n;i++){
        char curr=start[i];
        char goal=target[i];
        if(curr=='R'){
            if(waitL>0) return false;
            waitR+=1;
        }
        if (goal=='L'){
            if(waitR>0) return false;
            waitL+=1;
        }

        if(curr=='L'){
            if(waitL==0) return false;
            waitL-=1;
        }
        if(goal=='R'){
            if(waitR==0) return false;
            waitR-=1;
        }
    }

    return waitL==0 and waitR==0;
}
