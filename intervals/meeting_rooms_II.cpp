class Solution {
  public:
    // int minMeetingRooms(vector<int> &start, vector<int> &end) {
    //     // code here
    //     vector<vector<int>>meetings;
    //     int n=start.size();

    //     for(int i=0;i<n;i++){
    //         meetings.push_back({start[i],end[i]});
    //     }

    //     sort(meetings.begin(),meetings.end());

    //    priority_queue<int, vector<int>, greater<int>> pq; // min-heap of end times

    //     for (auto &m : meetings) {
    //         if (!pq.empty() && pq.top() <= m.first) {
    //             pq.pop(); // reuse room
    //         }
    //         pq.push(m.second);
    //     }

    //     return pq.size();
    // }

    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,bool>>timeline;
        for(auto i:intervals){
            timeline.push_back({i.start,true});
            timeline.push_back({i.end,false});
        }
        sort(timeline.begin(),timeline.end());

        int cnt=0,maxcnt=0;
        for(auto [time,isStart]:timeline){
            if(isStart){
                cnt+=1;
                maxcnt=max(maxcnt,cnt);
            }
            else{
                cnt-=1;
            }
        }

        return maxcnt;
    }
};
