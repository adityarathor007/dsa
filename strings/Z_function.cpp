vector<int>calculateZ(string s){
    //Z[i] tells us how many characters from position i onwards match with the beginning of the string.

    int n=s.size();
    vector z_arr(n,0);
    int L=0,R=0; //For Z box which tells which represents the rightmost substring that matches the prefix of the string.

    for(int i=1;i<n;i++){
        if(i>R){
            //scratch comparison(current index outside the box)
            L=R=i;
            while(R<n and s[R-L]==S[R])R++;
            Z[i]=R-L;
            R--; //as index at which comparison fails so we go back to index where it worked
        }
        else{
            int k=R-L; //k is the position within the prefix
            if(Z[k]<R-i+1){ //Z-value might extend beyond the current window [L,R] but this only gurantees matches upto R.
                Z[i]=Z[k];
            }
            else{
                // scratch comparision from index i
                L=i;
                while(R<n and s[R-L]==S[R])R+=1;
                Z[i]=R-L;
                R-=1;
            }

        }

    }
    return z;
}



vector<int>search(string&text,string&pattern){
    string s=pattern+'$'+text;
    vector<int>z=calculateZ(s);
    vector<int>pos;
    int m=pattern.size();

    for(int i=m+1;i<z.size();i++){
        if(z[i]==m){
            pos.push_back(i-m-1);
        }
    }

    return pos;
}
