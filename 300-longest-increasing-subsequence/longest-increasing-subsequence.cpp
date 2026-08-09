class Solution {

    int n;
    int help(int i, int prev, vector<int>& nums , vector<vector<int>> &  dp) {

        if (i == n)
            return 0;

            if( dp[i][prev+1] != -1) return dp[i][prev+1];

        // dont take
        int dont = help(i + 1, prev, nums , dp);

        // take
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + help(i + 1, i, nums , dp);
        }

        return dp[i][prev + 1] = max(take, dont);
    }

public:
    int lengthOfLIS(vector<int>& nums) {

        n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        // return help(0, -1, nums , dp);

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i-1; prev >= -1; prev --) {

                int dont = dp[i+1][prev +1 ]  ;
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i+1][i+1] ;
                }

                dp[i][prev + 1] = max(take, dont);
            }
        }

        return dp[0][-1+1];
    }
};