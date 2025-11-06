class Solution {
public:
    unordered_map<char,int> createMap(){
        unordered_map<char,int>c_to_i;
        c_to_i['I']=1;
        c_to_i['V']=5;
        c_to_i['X']=10;
        c_to_i['L']=50;
        c_to_i['C']=100;
        c_to_i['D']=500;
        c_to_i['M']=1000;

        return c_to_i;

    }

    bool sub_instance(int i,string&s){
        char cc=s[i];
        char nc=s[i+1];
        if(cc=='I' and (nc=='V' or nc=='X')) return true;
        if(cc=='X' and (nc=='L' or nc=='C')) return true;
        if(cc=='C' and (nc=='D' or nc=='M')) return true;

        return false; 
    }

    int romanToInt(string s) {
        int n=s.size();
        unordered_map<char,int>c_to_i=createMap();
        int ans=0;
        for(int i=0;i<n;i++){
            if(i!=n-1 and sub_instance(i,s)){
                ans=ans-c_to_i[s[i]]+c_to_i[s[i+1]];
                i+=1;
            }
            else{
                ans+=c_to_i[s[i]];
            }
        }
        return ans;
    }
};