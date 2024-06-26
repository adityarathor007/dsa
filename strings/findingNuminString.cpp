class Solution {
  public:
  
    bool not9(long long n){
        while(n!=0){
            long long temp=n%10;
            if(temp==9){
                return false;
            }
            n=n/10;
            
            
        }
        return true;
    }
  
    long long ExtractNumber(string sentence) {

        // code here
        stringstream ss(sentence);
        long long found;
        vector<long long>n;
        bool mod=false;
        string temp;
        while(!ss.eof()){
            ss>>temp;
            if(stringstream(temp)>>found and not9(found)){
                n.push_back(found);
                if(!mod){
                  mod=true;  
                }
                
            }
            temp="";
        }
        
        
        
        if(!mod){
            return -1;
        }
        return *max_element(n.begin(), n.end());
    }
};