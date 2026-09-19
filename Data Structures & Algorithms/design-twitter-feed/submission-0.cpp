

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

        

        bool left = true;


        while(result.size()<10 && left){
            priority_queue<pair<int,int>> pq;
            left = false;
            for(int id : followees){
                vector<pair<int,int>> v = dict[id];
                int n = v.size();
                //i need to take the last element of that v: 
                if(n){
                    if(!index.contains(id))index[id]=n-1;
                    if(index[id]<0)continue;
                }else{
                    continue;
                }
                pq.push({v[index[id]].first, id}); //time, userId;

            }
            if(pq.size()){
                pair<int,int> p = pq.top(); // time, userId;
                int ind = index[p.second]; // the index of the tweet;
                pair<int,int> p2 = dict[p.second][ind]; // the pair that contains the tweet
                int tweetId = p2.second;
                result.push_back(tweetId);
                index[p.second]--;
                left = true;
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
