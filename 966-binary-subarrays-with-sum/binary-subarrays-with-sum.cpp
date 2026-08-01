class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        

        int ans = 0 ;

        map<int , int> mpp;

        int n = nums.size();
        mpp[0] = 1;

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