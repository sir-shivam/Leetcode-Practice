class Solution {

    int help( int n , vector<int> & dp ){

        // one step down 


        if( n < 0  ) return 0 ;
        if( n == 0 ) return 1 ;

        if( dp[n] != -1) return dp[n];
        int one = help( n -1 , dp );

        // two step down 

        int two = help( n - 2 , dp);
        

        return dp[n] =  one + two ;



    }
public:
    int climbStairs(int n) {
        vector<int> dp( n+1 , -1);
        
        return help( n  , dp );
    }
};