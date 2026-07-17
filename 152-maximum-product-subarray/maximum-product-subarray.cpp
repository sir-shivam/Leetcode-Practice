class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // with help of prefix and suffix 

        int n = nums.size();
        int maxi = INT_MIN;
        int prd1 = 1;
        int prd2 = 1; 
        for(int i = 0 ; i < n ; i++){
            prd1 *= nums[i];
            prd2 *= nums[n-i -1];

            maxi = max({maxi , prd1 , prd2});
            if(prd1 == 0){
                prd1  = 1;
            }
            if(prd2 == 0){
                prd2 = 1;
            }
        }

        return maxi;
    }
};