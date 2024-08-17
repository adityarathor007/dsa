 #include<iostream>
 #include<vector>
 using namespace std;
 
 void generateAllStrings(int k,string str,vector<string>&ans,int n){
     if(n==k){
         ans.push_back(str);
         return ;
     }
     if(str[n-1]=='0'){
        generateAllStrings(k,str+"1",ans,n+1);
        generateAllStrings(k,str+"0",ans,n+1);
        
     }
     else{
         generateAllStrings(k,str+"0",ans,n+1);
     }
     return ;
    }

vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string>ans;
        string str1;
        str1+="0";
        generateAllStrings(num,str1,ans,1);
        string str2;
        str2+="1";
        generateAllStrings(num,str2,ans,1);
        return ans;
        
    }


int main(){
    auto ans=generateBinaryStrings(3);
    for(auto x:ans){
        cout<<x<<",";

    }
    cout<<endl;

}