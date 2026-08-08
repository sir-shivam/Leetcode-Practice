class Solution {
    int n, m;

    int help(int i, int j, string s, string t) {

        // dont take
        if (j == m)
            return 1;
        if (i == n)
            return 0;

        int dont = help(i + 1, j, s, t);

        int take = 0;
        if (s[i] == t[j]) {
            take = help(i + 1, j + 1, s, t);
        }

        return dont + take;
    }

public:
    int numDistinct(string s, string t) {

        m = t.size();
        n = s.size();
        vector<vector<long long >> dp( n+1 , vector<long long> ( m +1 , 0 ));

        for( int i = 0 ; i <= n ; i++){
            dp[i][m] = 1;
        }

        for (int i = n-1 ; i >= 0 ; i--) {

            for (int j = m-1 ; j >= 0 ; j--) {

                int dont =  dp[i+1][j] ;// help(i + 1, j, s, t);

                int take = 0;
                if (s[i] == t[j]) {
                    take = dp[i+1][j+1] ; // help(i + 1, j + 1, s, t);
                }

                dp[i][j] =  1LL*dont + 1LL*take;
            }
        }
        
        return dp[0][0];
    }
};