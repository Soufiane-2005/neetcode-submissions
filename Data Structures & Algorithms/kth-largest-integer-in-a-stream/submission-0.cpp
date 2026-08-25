class KthLargest {
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums){
            pq.push(num);
        }

    }
    
    int add(int val) {
        pq.push(val);
        vector<int> temp;
        int i = 0;
        while(i!=k){
            temp.push_back(pq.top());
            pq.pop();
            i++;
        }

        int x = temp.back();

        while(temp.size()){
            pq.push(temp.back());
            temp.pop_back();
        }
        return x;
    }
};
