class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;

        for(int stone : stones){
            pq.push(stone);
        }

        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x==y){
                continue;
            }
            int new_stone = abs(x-y);
            pq.push(new_stone);
            
        }
        
        return pq.size()==0?0:pq.top();
        
    }
};
