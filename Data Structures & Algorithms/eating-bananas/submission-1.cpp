class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {



        int max_k = *max_element(piles.begin(),piles.end());


        

        int k = max_k;

        int left = 1;
        int right = max_k;

        int middle = (left+right)/2;

        while(left<=right){

            int numberOfhours=0;
            for(int p=0; p<piles.size(); p++){
                numberOfhours+=(piles[p]+middle-1)/middle;
            }

            if(numberOfhours>h){
                left = middle+1;
            }else{
                k = min(k,middle);
                right = middle-1;
            }

            middle = (left+right)/2;

            
        }

        return k;



        



        

        



        
    }
};
