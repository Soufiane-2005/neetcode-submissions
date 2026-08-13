class Solution {
public:
    int maxProfit(vector<int>& prices) {


        int n = prices.size();

        if(n==1)return 0;
        

        unordered_map<int,int> profit;

        int best_profit=0;

        profit[n-1]=0;
        for(int i = n-2; i>=0; i--){
            int selling_dayafter_profit  = prices[i+1]-prices[i];
            profit[i] = max(max(selling_dayafter_profit,selling_dayafter_profit+profit[i+1]),0);

            if(profit[i]>best_profit){
                best_profit=profit[i];
            }
        }

        
        return best_profit;

        
    }
};
