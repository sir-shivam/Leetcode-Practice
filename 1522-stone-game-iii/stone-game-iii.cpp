class Solution {

    int help(int i , vector<int>& stoneValue , vector<int> &dp){

        int n = stoneValue.size();

        if(i >= n ) return 0;
        if(dp[i] != -1) return dp[i];
        int res = stoneValue[i] - help(i+1 , stoneValue , dp);

        if(i < n-1 ){
            res = max( res , stoneValue[i] + stoneValue[i+1] - help(i+2 , stoneValue , dp));
        }

        if( i < n-2){
            res = max( res , stoneValue[i] + stoneValue[i+1] +stoneValue[i+2] - help(i+ 3, stoneValue , dp));
        }

        return dp[i] =  res;

    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n , -1);
        int ans =  help(0 , stoneValue , dp);

        if(ans == 0) return "Tie";
        return  ans < 0 ? "Bob"  : "Alice";
    }
};