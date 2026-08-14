class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {



        int n = nums.size();

        if(n-k+1<=0)return {};

        int left=0;
        int right=0;
        vector<int> result;
        
        deque<int> deq;

        


        

        while(right<n){

            
            while(!deq.empty() && nums[right]>nums[deq.back()]){
                deq.pop_back();
                        
            }

            deq.push_back(right);

            
            if(right-left+1==k){
                if(deq.front()<left){
                    while(!deq.empty() && deq.front()<left ){
                        deq.pop_front();
                    }
                    
                }
                result.push_back(nums[deq.front()]);
                left++;
            }

            
            right++;
        }
        

        return result;
    }
};
