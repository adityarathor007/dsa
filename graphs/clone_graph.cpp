unordered_map<int,Node*>mp;
Node* cloneGraph(Node* node) {
    if(!node) return NULL;
    Node* dc_node=new Node(node->val);
    mp[node->val]=dc_node;

    for(auto neighbor:node->neighbors){
        int neighbor_val=neighbor->val;
        if(mp.find(neighbor_val)==mp.end()){
            dc_node->neighbors.push_back(cloneGraph(neighbor));
        }
        else dc_node->neighbors.push_back(mp[neighbor_val]); //via another path it is visited but for the dc_node its neightbour is not updated 
    }

    return dc_node;
}
