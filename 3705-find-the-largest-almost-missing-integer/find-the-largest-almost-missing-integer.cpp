class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Only one subarray: the whole array
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // k = 1 -> each element forms its own subarray
        if (k == 1) {
            unordered_map<int, int> freq;

            for (int x : nums) {
                freq[x]++;
            }

            int ans = -1;

            for (int x : nums) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }



        bool first = true;
        bool last = true;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[0]) {
                first = false;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[n - 1]) {
                last = false;
            }
        }

        int ans = -1;

        if (first) {
            ans = max(ans, nums[0]);
        }

        if (last) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};