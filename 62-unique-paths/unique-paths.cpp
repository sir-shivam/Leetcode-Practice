class Solution {
    int help(int i , int j , int m, int n , vector<vector<int>> &dp ){

        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        // right 
        int r = 0 ;
        if(j+1  < n ){
            r =  help(i , j+1 , m , n , dp);
        }

        int d = 0;
        if(i+1 < m ){
            d =  help(i +1 , j , m , n , dp);
        }

        return dp[i][j] =  r+d;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1 , vector<int> (n +1 , 0 ));

        dp[m-1][n-1]  = 1;

        for(int i = m-1; i >= 0 ; i --){
            for( int j = n-1 ; j >= 0 ; j--){
                if (i == m - 1 && j == n - 1)
                    continue;
                
                int  r = dp[i][j+1];

                int d = dp[i+1][j];

                dp[i][j] = r+d;
                
            }
        }
        return dp[0][0];

        return help(0 , 0 , m , n , dp);
    }
};