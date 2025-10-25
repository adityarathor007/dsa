#include<std/c++.h>
using namespace std;

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    
    //step1: converting strings to int so as to keep track of nodes
    unordered_map<string,int>strToInt;
    int num_eq=equations.size();
    int index=0;

    for(int i=0;i<num_eq;i++){
        string sn1=equations[i][0];
        string sn2=equations[i][1];
        if(strToInt.find(sn1)==strToInt.end()){
            strToInt[sn1]=index;
            index+=1;
        }
        if(strToInt.find(sn2)==strToInt.end()){
            strToInt[sn2]=index;
            index+=1;
        }

    }

    //Step2: creating adjMatrix for the above nodes (Constructing the graph)
    int num_nodes=strToInt.size();
    vector<vector<double>>adjMatrix(num_nodes,vector<double>(num_nodes,-1.0));

    for(int i=0;i<num_eq;i++){
        double wt=values[i];
        int n1=strToInt[equations[i][0]];
        int n2=strToInt[equations[i][1]];
        adjMatrix[n1][n2]=wt;
        adjMatrix[n2][n1]=1/wt;
    }

    //step3: finding the shortest paths for the given queries
    int num_queries=queries.size();
    vector<double>ans;

    for(int i=0;i<num_queries;i++){
        string sn1=queries[i][0];
        string sn2=queries[i][1];

        if(strToInt.find(sn1)==strToInt.end() or strToInt.find(sn2)==strToInt.end()) ans.push_back(-1);

        else if(sn1==sn2) ans.push_back(1);

        else{
            int n1=strToInt[sn1];
            int n2=strToInt[sn2];
            vector<double>dist(num_nodes,DBL_MAX);
            priority_queue<pair<double,int>>pq;
            
            pq.push({1.0,n1});
            int cn;

            while(!pq.empty()){
                auto cp=pq.top();
                pq.pop();
                double cd=cp.first;
                cn=cp.second;
                // cout<<cn<<" "<<cd<<endl;
                dist[cn]=cd;

                if(cn==n2){
                    // cout<<"h1"<<endl;
                    ans.push_back(dist[cn]);
                    break;
                }
                
                for(int i=0;i<num_nodes;i++){
                    if(adjMatrix[cn][i]!=-1.0 and dist[i]==DBL_MAX){
                        double nd=cd*adjMatrix[cn][i];
                        pq.push({nd,i});
                    }
                }

            }

            if(cn!=n2) ans.push_back(-1.0);
            // ans.push_back(1.0);

        }
        // cout<<"query complete"<<endl;
    }

    return ans;

}
