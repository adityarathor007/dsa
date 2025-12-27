class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        vector<vector<int>>meetings;
        int n=start.size();

        for(int i=0;i<n;i++){
            meetings.push_back({start[i],end[i]});
        }

        sort(meetings.begin(),meetings.end());

       priority_queue<int, vector<int>, greater<int>> pq; // min-heap of end times

        for (auto &m : meetings) {
            if (!pq.empty() && pq.top() <= m.first) {
                pq.pop(); // reuse room
            }
            pq.push(m.second);
        }

        return pq.size();
    }
};
