    vector<vector<int>> generateSchedule(int n) {
        vector<pair<int,int>> matches;
        // generating all the matchups
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                matches.push_back({i, j});
                matches.push_back({j, i});
            }
        }

        int total = matches.size();

        vector<int> lastPlayed(n, -1000000);
        vector<int> remaining(n, 2 * (n - 1));
        vector<bool> used(total, false);  //days which are to be used for matches
        vector<vector<int>> schedule;  //final ans

        // function call inside another function call
        function<bool(int)> dfs = [&](int day) {
            if(day == total) return true;
            vector<tuple<int,int,int,int>> candidates;

            for(int i = 0; i < total; i++){
                if(used[i]) continue;

                auto [a, b] = matches[i];

                if(lastPlayed[a] == day - 1 || lastPlayed[b] == day - 1)
                    continue;

                int score = remaining[a] + remaining[b];
                candidates.push_back({-score, i, a, b});
            }

            sort(candidates.begin(),candidates.end()); //based on which team has the highesht combined remaining games

            for(auto &[score, idx, a, b] : candidates){
                used[idx] = true;
                schedule.push_back({a, b});

                int prevA = lastPlayed[a];
                int prevB = lastPlayed[b];

                lastPlayed[a] = day;
                lastPlayed[b] = day;

                remaining[a]--;
                remaining[b]--;

                 if(dfs(day + 1))
                    return true;

                schedule.pop_back();

                used[idx] = false;
                lastPlayed[a] = prevA;
                lastPlayed[b] = prevB;

                remaining[a]++;
                remaining[b]++;

            }
            return false;
        };

        if(dfs(0))
            return schedule;

        return {};

    }
