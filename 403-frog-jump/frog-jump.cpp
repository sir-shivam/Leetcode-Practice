class Solution {

    map<int , int> mpp;
    int n ;

    bool help( int i , int k ,  vector<int>& stones ,  vector<vector<int>>  &dp ){

        // k-1 steps 

        if( i == n-1 ) return 1;
        if( dp[i][k] != -1) return dp[i][k];
        for( int m = -1 ; m <= 1 ; m++){
            if( k + m  == 0 ) continue;
            if(mpp.count(stones[i]+ k+m)){

                if(mpp[stones[i]+k+m] == n-1){
                    return dp[i][k] =  true;
                }

                if(help( mpp[stones[i]+k+m] , k+m , stones , dp)){
                    return dp[i][k] =  true;
                };
            }
        }

        return  dp[i][k] =  false;;


    }
public:
    bool canCross(vector<int>& stones) {
        
        n = stones.size();
        if( stones[1] != 1) return false;

        vector<vector<int>> dp( n , vector<int> ( n +1 , -1));

        for( int i = 0 ;i < n ; i++){
            mpp[stones[i]] = i ;
        }

        return help( 1 , 1 , stones , dp);
    }
};