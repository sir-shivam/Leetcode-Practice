class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        
        int n = nums.size();

        int ans = 0 ;

        for( int i = 0 ; i < n ; i++){

            int x = 0 ;
            int y = 0 ;
            for( int j = i ; j < n ; j++){
                if(nums[j] % 2 ){
                    y ++;
                }else {
                    x ++;
                }

                if( x* b <= y * a){
                    ans++;
                }
            }
        }

        return ans;
    }
};