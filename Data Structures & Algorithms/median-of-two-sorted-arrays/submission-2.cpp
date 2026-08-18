class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {


        int n = nums1.size();
        int m = nums2.size();



        int total = n+m;


        int half = total/2;
        


        int left = 0;

        int right = n-1;

        int middle;



        int partition1 = (left+right+1)/2;

        int partition2 = half -partition1;


        double a,b,c,d;


        partition1==0?a=INT_MIN:a=nums1[partition1-1];
        partition1==n?b=INT_MAX:b=nums1[partition1];

        partition2==0?c=INT_MIN:c=nums2[partition2-1];
        partition2==m?d=INT_MAX:d=nums2[partition2];


        


        while(a>d || c>b){

            middle = (left+right)/2;

            if(a>d){
                right = middle-1;
            }
            if(c>b){
                left = middle+1;
            }

            partition1 = (left+right+1)/2;

            partition2 = half -partition1;

            partition1==0?a=INT_MIN:a=nums1[partition1-1];
            partition1==n?b=INT_MAX:b=nums1[partition1];

            partition2==0?c=INT_MIN:c=nums2[partition2-1];
            partition2==m?d=INT_MAX:d=nums2[partition2];

        }









        

        


        if((total)%2==0){
            return (max(a,c)+min(b,d))/2;
        }else{
            return min(b,d);
        }

        

        


        

        

        

       
        




        



       




        
    }
};
