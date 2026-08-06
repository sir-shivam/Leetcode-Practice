class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        map<int , int > mpp;
        mpp[0] = 1;

        int j = 0 ; 

        int n = nums.size();
        int ans = 0 ;

        int sum = 0 ;
        for( int i = 0 ; i < n ; i++){
            sum += nums[i];

            int rem = sum - goal;

            if(mpp.count(rem)){
                ans += mpp[rem];
            }

            mpp[sum] ++;
        }

        return ans;
    }
};