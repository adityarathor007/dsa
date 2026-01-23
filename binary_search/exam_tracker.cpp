// **
//  * Your ExamTracker object will be instantiated and called as such:
//  * ExamTracker* obj = new ExamTracker();
//  * obj->record(time,score);
//  * long long param_2 = obj->totalScore(startTime,endTime);

// ExamTracker(): Initializes the ExamTracker object.
// void record(int time, int score): Alice takes a new exam at time time and achieves the score score.
// long long totalScore(int startTime, int endTime): Returns an integer that represents the total score of all exams taken by Alice between startTime and endTime (inclusive). If there are no recorded exams taken by Alice within the specified time interval, return 0.

// It is guaranteed that the function calls are made in chronological order. That is,
// Calls to record() will be made with strictly increasing time.
// Alice will never ask for total scores that require information from the future. That is, if the latest record() is called with time = t, then totalScore() will always be called with startTime <= endTime <= t.
vector<pair<int,long long>>prefixMarks;
ExamTracker() {

    }

    void record(int time, int score) {
        long long current_score = (prefixMarks.empty() ? 0 : prefixMarks.back().second) + score;
        prefixMarks.push_back({time, current_score});
    }

    long long totalScore(int startTime, int endTime) {

        //startTime-1 because we remove the prefix score before startTime
        // int si=findNearestNext(startTime-1);
        int si=upper_bound(prefixMarks.begin(),prefixMarks.end(),make_pair(startTime-1,INT_MIN))-prefixMarks.begin();
        if(prefixMarks[si].first!=(startTime-1)){
            si-=1;
        }
        // int ei=findNearestNext(endTime);
        int ei=upper_bound(prefixMarks.begin(),prefixMarks.end(),make_pair(endTime,INT_MIN))-prefixMarks.begin();
        if(prefixMarks[ei].first!=endTime){
            ei-=1;
        }

        // cout<<startTime<<" "<<endTime<<endl;
        // cout<<si<<" "<<ei<<endl;

        long long start_score=0;
        if(si>=0) start_score+=prefixMarks[si].second;

        long long end_score=0;
        if(ei>=0) end_score+=prefixMarks[ei].second;

        return end_score-start_score;

    }
