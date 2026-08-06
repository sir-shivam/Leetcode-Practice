class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int one = 0 ;
        int flip = 0 ;
        int n = nums.size();
        int ans = 0 ;

        int j = 0 ;
        for( int i = 0 ; i < n ; i++){

            if(nums[i]){
                one ++;
            }else{
                flip ++;
            }

            while( j <= i && flip > k){
                if(nums[j]){
                    one --;
                }else{
                    flip --;
                }
                j++;
            }

            ans = max( ans , flip + one );
        }

        return ans;
    }
};