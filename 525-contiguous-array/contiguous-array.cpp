class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int , int> mpp;

        mpp[0] = -1;

        int ans = 0 ;

        int n = nums.size();

        int sum = 0 ;

        for( int i = 0 ; i < n ; i++){
            sum += nums[i] == 0 ? -1 : 1 ;

            if(mpp.count(sum)){
                ans = max( ans , i -  mpp[sum] );

                continue;
            }

            mpp[sum] = i ;
            
        }

        return ans;
    }
};