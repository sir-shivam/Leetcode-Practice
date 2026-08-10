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
        vector<int> dp( n+1 , 0);
        dp[0] = 1;

        for( int i = 1 ; i <=  n ; i++){

            int one = dp[i-1];

            int two = 0 ; 
            if( i >= 2 ){
                two = dp[i-2];
            }
            dp[i] = one + two;
        }

        return dp[n];
        
        // return help( n  , dp );
    }
};