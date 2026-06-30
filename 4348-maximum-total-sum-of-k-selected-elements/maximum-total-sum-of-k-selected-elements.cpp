class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        const int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long sum = 0;
        int i = n - 1;

        while (k > 0) {
            if (mul > 1) {
                sum = (sum + 1LL * mul * nums[i]) ;
            } else {
                sum = (sum + nums[i]) ;
            }
            i--;
            mul--;
            k--;
        }

        return sum;
    }
};