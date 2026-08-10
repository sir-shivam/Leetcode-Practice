class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        

        int n = prices.size();
        vector<vector<int>> dp( n +1 , vector<int> ( 2  , 0 ));

        for( int i = n-1 ; i >= 0  ; i -- ){

            for( int b = 0 ; b < 2 ; b++){
                int dont = dp[i+1][b];

                int buy  = -1e9;

                if(b == 0 ){
                    buy = - prices[i] + dp[i+1][1];
                }

                int sell = -1e9 ;

                if( b == 1 ){
                    sell = prices[i] - fee + dp[i+1][0];
                }

                dp[i][b] = max({ dont , buy , sell});
            }
        }

        return dp[0][0];
    }
};