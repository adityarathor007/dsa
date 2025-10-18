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

ExamTracker() {
       
    }
    
    void record(int time, int score) {
        long long current_score = (exams.empty() ? 0 : exams.back().second) + score;
        exams.push_back({time, current_score});
    }
    
    long long totalScore(int startTime, int endTime) {
        if(exams.empty()) return 0;
        
        auto prefixAt = [&](int t) -> long long {
            auto it = upper_bound(exams.begin(), exams.end(), make_pair(t, LLONG_MAX));
            if (it == exams.begin()) return 0;
            --it;
            return it->second;
        };

        long long total = prefixAt(endTime) - prefixAt(startTime - 1);
        return total;
    }