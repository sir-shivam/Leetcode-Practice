class Solution {
    int help(int i, vector<int>& nums, int prev, vector<vector<int>>& dp) {

        int n = nums.size();
        if (i >= n)
            return 0;
        if (dp[i][prev] != -1)
            return dp[i][prev];
        // dont rob
        int dont = help(i + 1, nums, prev, dp);

        // rob
        int rob = 0;
        if (prev + 1 != i) {
            rob = nums[i] + help(i + 1, nums, i, dp);
        }

        return dp[i][prev] = max(dont, rob);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n-1; i >= 0 ; i--) {
            for (int prev = n - 1; prev >= 0; prev--) {
                int dont = dp[i + 1][prev]; //  help(i+1 , nums , prev , dp);
                int rob = 0;
                if ( prev == n || prev + 1 != i) {
                    rob = nums[i] + dp[i+1][i] ;// help(i + 1, nums, i, dp);
                }

            dp[i][prev] = max(dont , rob);
            }
        }

        return dp[0][n-1] ;// help(0, nums, n - 1, dp);
    }
};