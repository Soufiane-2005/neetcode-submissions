class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> dict;
        for(char task : tasks)dict[task]++;

        priority_queue<int> pq;
        for(auto& [task,count] : dict)pq.push(count);

        queue<pair<int,int>> cooldown;

        int time = 0;

        while(!pq.empty() || !cooldown.empty()){

            while(!cooldown.empty() && cooldown.front().second<=time){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            if(!pq.empty()){
                int remaining = pq.top();
                pq.pop();

                remaining--;
                if(remaining>0)cooldown.push({remaining, time+n+1});
            }
            time++;

        }

        return time;

        
    }
};