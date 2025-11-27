class Solution {
public:
    int calculate(string s) {
        long long int sum=0;
        int sign=1;
        stack<pair<int,int>>st;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                long long int num=0;
                while(i<n and isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i+=1;
                }
                i-=1;
                sum+=num*sign;
                sign=1;
            }
            else if(s[i]=='('){
                st.push({sum,sign});
                sum=0; //restoring for calculating the inner bracket
                sign=1;
            }
            else if(s[i]==')'){
                sum=st.top().first+(st.top().second*sum);  //sum contains the inner bracket value and sign is the information before the bracket
                st.pop();
            }

            else if(s[i]=='-'){
                sign=-1*sign;
            }
        }
        return sum;
    }
};
