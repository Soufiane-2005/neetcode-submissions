

class Twitter {
    unordered_map<int,vector<pair<int,int>>> dict;
    unordered_map<int,unordered_set<int>> following;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        dict[userId].push_back({time,tweetId});
        time++;
        
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int> result;

        unordered_set<int> followees = following[userId];

        followees.insert(userId);

        unordered_map<int,int> index;

        


        priority_queue<pair<int,int>> pq;

        for(int id : followees){

            vector<pair<int,int>>& v = dict[id];

            int n = v.size();

            if(!v.empty()){
                index[id] = n-1;
                pq.push({v[n-1].first,id}); // time and userId;
            }
            
           

        }


        while(pq.size() && result.size()<10){
           
           
           
            pair<int,int> p = pq.top(); // time, userId;
            pq.pop();
            int ind = index[p.second]; // the index of the tweet;
            pair<int,int> p2 = dict[p.second][ind]; // the pair that contains the tweet
            int tweetId = p2.second;
            result.push_back(tweetId);
            index[p.second]--;

            if(index[p.second]>=0){
                pq.push({dict[p.second][index[p.second]].first, p.second});
            }
    
            
        }
        

        

        


       

        return result;




        



        
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
