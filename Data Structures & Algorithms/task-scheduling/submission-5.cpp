class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {


        unordered_map<char,int> dict;

        for(char task : tasks)dict[task]++;
       
        priority_queue<int> max_heap;

        queue<pair<int,int>> q;

        int clock = 0;

        for(auto& [key,val] : dict)max_heap.push(val);

        while(max_heap.size() || q.size()){

            if(q.size() && q.front().second<=clock){
                max_heap.push(q.front().first);
                q.pop();
            }

            if(!max_heap.size()){
                clock++;
                continue;
            }

            int task = max_heap.top();
            int x = task - 1;
            clock++;
            if(x){
                q.push({x,clock+n});
            }

            max_heap.pop();      

        }

        return clock;



       
    }
};