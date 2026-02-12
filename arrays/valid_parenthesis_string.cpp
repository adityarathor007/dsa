bool checkValidString(string s) {
        int mini=0,maxi=0,n=s.size();
        for(char ch:s){
            if(ch=='('){
                mini+=1;
                maxi+=1;
            }
            else if(ch==')'){
                mini-=1;
                maxi-=1;
            }
            else{
                mini-=1;
                maxi+=1;
            }
            if(mini<0) mini=0;  //because the stars which make mini negative are not worth it
            if(maxi<0) return false;
        }

        if(mini==0) return true;
        return false;
    }
