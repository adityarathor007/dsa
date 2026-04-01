class Solution {
public:

    // cant ignore now
    bool helper(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i+=1;
            j-=1;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                i+=1;
                j-=1;
            }
            else{
                return helper(s,i+1,j) or helper(s,i,j-1);
            }
        }
        return true;
    }
};
