  int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(),courses.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        int n=courses.size();
        int current_time=1;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(courses[i][0]);
            current_time+=courses[i][0];
            if(current_time-1>courses[i][1]){
                current_time-=pq.top();
                pq.pop();
            }
        }
        return pq.size();

    }
