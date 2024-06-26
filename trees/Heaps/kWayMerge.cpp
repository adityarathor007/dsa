#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        int index;
        int arr_index;
        
        Node(int d,int i,int a_i){
            data=d;
            index=i;
            arr_index=a_i;
        }
};

class Compare{
    public:
        bool operator()(Node A,Node B){
            return A.data>B.data;
        }
};

vector<int> KwayMerge(int a1[],int a2[],int a3[],int s1,int s2,int s3){
    
    priority_queue<Node,vector<Node>,Compare > min_heap;
    vector<int> ans;
    
    min_heap.push(Node(a1[0],0,0));
    min_heap.push(Node(a2[0],0,1));
    min_heap.push(Node(a3[0],0,2));
    
    
    
    while(!min_heap.empty()){
        Node min_node=min_heap.top();
        int min_arr=min_node.arr_index;
        int j=min_node.index;
        cout<<"The minimum value of node is: "<<min_node.data<<endl;
        ans.push_back(min_node.data);
        min_heap.pop();
        if(min_arr==0 and j<s1-1){
            min_heap.push(Node(a1[j+1],j+1,min_arr));
        }
        else if (min_arr==1 and j<s2-1) {
            min_heap.push(Node(a2[j+1],j+1,min_arr));
        }
        else if(min_arr==2 and j<s3-1){
            min_heap.push(Node(a3[j+1],j+1,min_arr));
        }
        
    }
    
    return ans;


    
    
    
}

int main(){
    int k;
    int a1[]={1,3,15};
    int s1=sizeof(a1)/sizeof(a1[0]);
    int a2[]={2,4,6};
    int s2=sizeof(a2)/sizeof(a1[0]);
    int a3[]={0,9,10,11};
    int s3=sizeof(a3)/sizeof(a3[0]);
    auto ans=KwayMerge(a1,a2,a3,s1,s2,s3);
    for(int x:ans){
        cout<<x<<",";
    }
    cout<<endl;
    return 0;
}