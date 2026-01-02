class Solution {
public:
    vector<int> computeLPSArray(string& pattern){
        int n=pattern.size();
        vector<int>lps(n,0);
        int len=0; //len of the previous prefix which was a suffix
        int i=1; //starting from index 1 so that prefix and suffix are distinguishable

        while(i<n){
            if(pattern[i]==pattern[len]){
                len+=1;
                lps[i]=len;
                i+=1;
            }
            else{
                if(len!=0) len=lps[len-1];
                else{
                    lps[i]=0;
                    i+=1;
                }
            }
        }

        return lps;

    }

    int search(string haystack, string needle, vector<int>& lps_arr){

        int n=haystack.size();
        int m=needle.size();

        int i=0,j=0;

        while(i<n){
            if(haystack[i]==needle[j]){
                i+=1;
                j+=1;
                if(j==m) return i-m;
            }
            else{
                if(j!=0) j=lps_arr[j-1];
                else i+=1;
            }

        }
        return -1;
    }


    int strStr(string haystack, string needle) {
        // int n=haystack.size();
        // int m=needle.size();

        // for(int i=0;i<=n-m;i++){
        //     if(haystack[i]!=needle[0]) continue;  //if the first char does not match
        //     if(haystack.substr(i,m)==needle) return i;
        // }
        // return -1;


        // using the kmp algorithm
        auto lps_arr=computeLPSArray(needle);
        return search(haystack,needle,lps_arr);
    }
};
