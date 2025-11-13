int computeResult(int n1,int n2,string op){
            if(op=="+") return n1+n2;
            if(op=="-") return n1-n2;
            if(op=="*") return n1*n2;
            return n1/n2;
    }

    bool isOperator(string token){
        if(token=="+" or token=="-" or token=="*" or token=="/") return true;
        return false;
    }

    int evalRPN(vector<string>& tokens) {

        stack<int>st;

        for(string token:tokens){
            if(isOperator(token)){
                int n2=st.top();
                st.pop();
                int n1=st.top();
                st.pop();
                st.push(computeResult(n1,n2,token));
            }
            else st.push(stoi(token));
        }

        return st.top();
    }
