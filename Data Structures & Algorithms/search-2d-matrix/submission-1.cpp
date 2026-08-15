class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {


        int n = matrix.size();
        int m = matrix[0].size();

        int left,right,middle;
        

        left = 0;

        right = n*m-1;

        middle = (left+right)/2;
       

        while(left<=right){

            if(target<matrix[middle/m][middle%m]){
                right = middle -1;
            }else if(target>matrix[middle/m][middle%m]){
               left = middle + 1;
            }else{
                return true;
            }


            middle = (left+right)/2;



        }


        return false;
        
        
    }
};
