class Solution {

    int help( int i , vector<int> & coins , int amount , vector<vector<int>> &  dp){

        if( i == coins.size() - 1){
            if( amount % coins[i] == 0 ){
                return amount / coins[i] ;
            }
            return 1e9 ;
        }
        if( dp[i][amount ] != -1) return dp[i][amount];
        // dont take 
        int dont = help(i+1 , coins , amount , dp );

        int take = 1e9 ;
        if( coins[i] <= amount ){
            take = 1 + help(i , coins , amount - coins[i] , dp);
        }

        return dp[i][amount] =  min( dont , take );

    }

public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp( n ,vector<int> ( amount +1 , -1) );
        int t = help( 0 , coins , amount , dp);

        return t == 1e9 ? -1 : t ;

    }
};