 // optimal strategy is to remove the further opponents if present as the previous opponent has already used his power so wont harm them
string predictPartyVictory(string senate) {
        queue<int>rad,dist;
        int n=senate.size();

        for(int i=0;i<n;i++){
            if(senate[i]=='R') rad.push(i);
            else dist.push(i);
        }

        //Use increasing n to keep of position
        while(!rad.empty() and !dist.empty()){
            if(rad.front()<dist.front()) rad.push(n++);
            else dist.push(n++);  //moving the winner to the last as the senator who have already voted  will not be a problem to the other teams for that round so it is beter to remove the senator who has power to vote

            rad.pop(),dist.pop();
        }
        return rad.empty()?"Dire":"Radiant";

    }
