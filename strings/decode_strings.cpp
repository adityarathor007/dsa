     int i=0;
        return decode(s,i);
    }

    string decode(const string&s, int& i){  //index also passed by reference 
        string result="";
        int curr_reps=0;
        while(i<s.size()){
            char ch=s[i];
            if(isdigit(ch)){
                curr_reps=curr_reps*10+(ch-'0');
                i+=1;
            }
            else if(ch=='['){
                i+=1;
                string inner=decode(s,i);
                for(int k=0;k<curr_reps;k++){
                    result+=inner;
                }
                curr_reps=0;
            }
            else if(ch==']'){
                i+=1;
                return result;
            }
            else{
                result+=ch ;
                i+=1;
            }
        }
        return result;
    }