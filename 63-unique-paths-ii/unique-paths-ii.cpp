class Solution {
    int help(int i , int j , int m, int n , vector<vector<int>> &dp  , vector<vector<int>> &grid ){

        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        // right 
        int r = 0 ;
        if(j+1  < n && grid[i][j+1] == 0 ){
            r =  help(i , j+1 , m , n , dp , grid);
        }

        int d = 0;
        if(i+1 < m  && grid[i+1][j] == 0){
            d =  help(i +1 , j , m , n , dp , grid);
        }

        return dp[i][j] =  r+d;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1) return 0;
        vector<vector<long long >> dp(m+1 , vector<long long> (n +1, 0 ));

        for( int i = m-1 ; i >= 0 ; i --){
            for( int j = n-1 ; j >= 0 ; j --){
                if(i == m-1 && j == n-1 ){
                    dp[i][j] = 1;
                    continue;
                }

                int r = 0 ;
        if(j+1  < n && grid[i][j+1] == 0 ){
            r =  dp[i][j+1] ;// help(i , j+1 , m , n , dp , grid);
        }

        int d = 0;
        if(i+1 < m  && grid[i+1][j] == 0){
            d =  dp[i+1][j] ;// help(i +1 , j , m , n , dp , grid);
        }

        dp[i][j] = 1LL* r+ d;


            }
        }

        return dp[0][0];


        // return help(0 , 0 , m , n , dp , grid);
    }
};