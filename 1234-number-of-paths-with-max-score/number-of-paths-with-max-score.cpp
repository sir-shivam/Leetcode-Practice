class Solution {

    int MOD = 1e9 + 7 ;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();
        int m = board[0].size();
        
        board[n-1][m-1] = '0';
        vector<vector<pair<long long  , int>>> dp(n+1 , vector<pair<long long  , int>>( m + 1 , { -1 , 0 }));
        board[0][0] = '0';

        dp[n][m] = {0 , 1};


        for(int i = n-1 ;i >= 0 ; i--){
            for( int j = m-1 ; j >= 0 ; j--){
                
                int cnt = 0 ;
                // left 
            
                auto curr = dp[i+1][j+1];

                if(curr.first == -1 ) continue;

                if(j - 1 >= 0 && board[i][j-1] != 'X'){
                    long long  sum = (curr.first +  board[i][j-1] -'0') % MOD;

                    auto next = dp[i+1][j];

                    if(sum  > next.first ){
                        dp[i+1][j] = {sum  , curr.second};
                    }else if(sum == next.first ){
                        dp[i+1][j].second = ( curr.second + next.second) % MOD;
                    }

                    cnt ++;

                }



                // up 

                if(i-1 >= 0 && board[i-1][j] != 'X'){
                    long long  sum = (curr.first + board[i-1][j] - '0') % MOD;

                    auto next = dp[i][j+1];

                    if(sum > next.first){
                        dp[i][j+1] = {sum , curr.second};
                    }else if (sum == next.first){
                        dp[i][j+1].second = ( curr.second + next.second) % MOD;
                    }

                    cnt ++;

                }

                // diagonal 

                if( i -1 >= 0 && j -1 >= 0 && board[i-1][j-1] != 'X'){
                    long long  sum = (curr.first + board[i-1][j-1] - '0') %MOD;

                    auto next = dp[i][j];
                    if(sum > next.first ){
                        dp[i][j] = {sum , curr.second };
                    }else if(sum == next.first ){
                        dp[i][j].second = ( curr.second + next.second) % MOD;
                    }

                    cnt ++;
                }

                
            }
        }

        if(dp[1][1].first == -1 ){
            return { 0 , 0 }; 
        }

        return {(int)dp[1][1].first , dp[1][1].second };

    }
};


/*


          st thid stop what is maxi and how many way to reach at this point  <- start


          it means its dp 

          dp[n-1][m-1] will we maxi = 0 and way = 0 ;

          now dp[n-1][m-2] = mai = max( sum , and way ++)

*/