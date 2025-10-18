// Records the new person's entry time
// Forgets about the ping that comes more than 3 seconds ago

RecentCounter() {
        
    }
    
int ping(int t) {
        q.push(t);
        while(!q.empty() and q.front()<t-3000) q.pop();
        return q.size();
    }
    