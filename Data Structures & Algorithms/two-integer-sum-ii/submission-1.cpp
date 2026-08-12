class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> result(2);

        int i = 0;
        int j = numbers.size()-1;

        while(i<j && (numbers[i]+numbers[j]!=target)){

            
            if(numbers[i]+numbers[j]>target){
                j--;
            }else if(numbers[i]+numbers[j]<target){
                i++;
            }
 

        }

        result[0]=i+1;
        result[1]=j+1;

        return result;

        
        
    }
};
