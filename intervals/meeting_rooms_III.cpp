struct customComp {
    bool operator()(auto& a, auto& b) const {
        if(a.first==b.first) return a.second>b.second;
        return a.first > b.first;
    }
};


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int>meetingCount(n);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRooms;

        priority_queue<int, vector<int>, greater<int>> unusedRooms;

        for(int i=0;i<n;i++) unusedRooms.push(i);

        for(auto meeting:meetings){
            int start=meeting[0],end=meeting[1];

            // empty all rooms which are before the current meeting start time
            while(!usedRooms.empty() and usedRooms.top().first<=start){
                int room=usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }

            // there are unused rooms present
            if(!unusedRooms.empty()){
                int room=unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end,room});
                meetingCount[room]+=1;
            }

            //all rooms are busy (take out the room which will end the earliest)
            else{
                auto [prev_end_time,room]=usedRooms.top();
                usedRooms.pop();
                int duration=end-start;
                usedRooms.push({duration+prev_end_time,room});
                meetingCount[room]+=1;
            }
        }

        int maxMeetingCnt=0,maxMeetingRoom=-1;
        for(int i=0;i<n;i++){
            if(meetingCount[i]>maxMeetingCnt){
                maxMeetingCnt=meetingCount[i];
                maxMeetingRoom=i;
            }
        }
        return maxMeetingRoom;

    }
};
