class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
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
      
        int i = 0;

        int n = pq.size();

        while(i!=n-k){
            pq.pop();
            i++;
        }

       
        return pq.top();
    }
};
