 // optimal strategy is to remove the further opponents if present as the previous opponent has already used his power so wont harm them
string predictPartyVictory(string senate) {
        int start=senate[0];
        bool same=true;
        for(char ch:senate){
            if(ch!=start){
                same=false;
                break;
            }
        }
        if(same){
            return start=='R'?"Radiant":"Dire";
        }

        stack<char>st;
        string str=""; //those which dont have power now
        for(char ch:senate){
            if(st.empty()) st.push(ch);
            else{
                if(ch=='R'){
                    if(st.top()=='D'){
                        st.pop();
                        str+='D';
                    }
                    else st.push('R');
                }
                if(ch=='D'){
                    if(st.top()=='R'){
                        st.pop();
                        str+='R';
                    }
                    else st.push('D');
                }
            }
        }

        // removing those which dont have option to attack
        if(!st.empty()){
            char target=st.top()=='R'?'D':'R';
            string nxt="";
            string xtra="";
            while(!st.empty()){
                xtra+=st.top();
                st.pop();
            }
            int i=0;
            for(char ch:str){
                if(ch!=target) nxt+=ch;
                else{
                    if(i<xtra.size()) i+=1;
                    else nxt+=ch;
                }
            }
            str=nxt;
            str+=xtra;

        }
        return predictPartyVictory(str);
    }
