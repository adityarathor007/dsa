#include <iostream>
#include <queue>
#include <set>
using namespace std;



class Twitter {
    unordered_map<int, vector<pair<int, int>>> posts; 
    unordered_map<int,set<int>>followings;
    int time;

public:
    struct Comparator{
        bool operator()(const pair<int,int>a,const pair<int,int>b){
            return a.second<b.second;
        }
    };

    Twitter(){
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back(make_pair(tweetId,time));
        time+=1;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comparator>pq;

        for(const auto& post: posts[userId]){
            pq.push(post);
        }
        for(int followee: followings[userId]){
            for(const auto& post: posts[followee]){
                pq.push(post);
            }
        }

        while(!pq.empty()){
            pair<int,int>t1=pq.top();
            pq.pop();
            ans.push_back(t1.first);
            if(ans.size()==10){
                break;
            }
        }


        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
       
    
    void unfollow(int followerId, int followeeId) {
        cout<<"unfollow api call came"<<endl;
        
        // auto it=find(followings[followerId].begin(),followings[followerId].end(),followeeId);
        // if(it!=followings[followerId].end()){
        //     followings[followerId].erase(it);
        // }

        if (followings.count(followerId) and followings[followerId].count(followeeId)) {
            followings[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */