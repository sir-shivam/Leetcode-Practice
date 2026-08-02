class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {

        long long maxi = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                long long g = __gcd(nums[i], nums[j]);

                long long temp = 1LL * nums[i] * nums[j] / (g * g);

                maxi = max(maxi, temp);
            }
        }

        return maxi;
    }
};