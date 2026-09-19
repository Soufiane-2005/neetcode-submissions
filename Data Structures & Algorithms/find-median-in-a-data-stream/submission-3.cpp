class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int> , greater<int>> min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!max_heap.empty()){
            int x = max_heap.top();
            if(num>=x){
                min_heap.push(num);
            }else{
                max_heap.push(num);
            }
        }else{
            max_heap.push(num);
        }

        if(!min_heap.empty() && min_heap.size()>max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if(!max_heap.empty() && max_heap.size()>min_heap.size()+1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        
    }
    
    double findMedian() {  
        if(min_heap.size()==max_heap.size()){
            double x = min_heap.top();
            double y = max_heap.top();
            return (x+y)/2;
        }else{
            return max_heap.top();
        }

    }
};
