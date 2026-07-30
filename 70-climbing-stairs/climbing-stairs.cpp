class Solution {
    int help(int n , vector<int> &dp){
        
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        int one = help( n -1 , dp);

        int two = 0;
        if(n >= 2){
            two = help(n -2 , dp);
        }

        return dp[n] =  one + two;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1 , 0 );

        dp[0]= 1;
        dp[1] = 1;

        for( int i = 2 ; i <= n ; i++){
            int one =  dp[i-1] ;//help( n -1 , dp);
            int two = 0;
            if( i >= 2){
            two = dp[i-2];// help(i  -2 , dp);
            }

            dp[i] = one + two;
        }



        return dp[n];// help(n , dp);

    }
};